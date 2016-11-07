#!/usr/bin/env python2
# -*- coding: utf-8 -*-
#
# Copyright (c) 2012, Sascha Schade
# Copyright (c) 2016, Daniel Krebs
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
# -----------------------------------------------------------------------------

"""Configuration Utility for pre-programmed DFU USB bootloader in Atmel AVR32 UC3 devices.

Configure the last 32-bit word of the user page that is evaulated by the bootloader.

See README.md for a in-depth documentation.  

Copyright 2012 Sascha Schade
"""

import sys
import os
import getopt
import numpy as np

class crc8:
    """CRC 8 code from https://www.cgran.org/browser/projects/ucla_zigbee_phy/branches/cwna06/src/python/crc8.py?rev=42
    with new table for CRC polynom x^8 + x^2 + x + 1
    """
    def __init__(self):
        self.crcTable = (   0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
                            0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
                            0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
                            0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
                            0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
                            0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
                            0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
                            0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
                            0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
                            0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
                            0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
                            0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
                            0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
                            0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
                            0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
                            0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
                            0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
                            0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
                            0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
                            0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
                            0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
                            0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
                            0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
                            0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
                            0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
                            0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
                            0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
                            0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
                            0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
                            0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
                            0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
                            0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3)

    def crc(self, msg):
        runningCRC = 0
        for c in msg:
            runningCRC = self.crcByte(runningCRC, c)
        return runningCRC
    
    def crcByte(self, oldCrc, byte):
        res = self.crcTable[byte ^ oldCrc]
        return res 

def process(low, pin):
    # debug print
    pin = int(pin)
    
    if (0 <= pin) and (pin <= 109):
        pass
    else:
        print "Pin %d is an invalid pin." % pin
        return
    
    print "The GPIO pin number to test during the boot process: %d" % pin
    print "Active level of ISP_IO_COND_PIN                    :",
    if low == True:
        print "low level"
    else:
        print "high level"  
    
    # create empty user-page, 128 words of 4 bytes
    userpage = np.zeros(128*4, np.uint8) 
    
    # set 3 config bytes
    userpage[-4] = 0x92     # Key
    userpage[-3] = 0x9E     # Key
    userpage[-2] = pin      # pin
    
    if low == True:
        pass
    else:
        userpage[-2] += 0x80
    
    # set 4th config byte with CRC8
    crc = crc8()   
    userpage[-1] = crc.crc(userpage[-4:-1])
    
    # print config bytes:
    print "Config bytes: ", hex(userpage[-4]), hex(userpage[-3]), hex(userpage[-2]), hex(userpage[-1])

    # open file and write userpage.bin
    f = open('userpage.bin', 'w')
    f.write(userpage)
    f.close()
    
    # convert userpage.bin to userpage.hex
    cmd = 'avr32-objcopy -O ihex -I binary userpage.bin userpage.hex'
    os.system(cmd)

def main():
    # parse command line options
    try:
        opts, args = getopt.getopt(sys.argv[1:], "h", ["help","low","high"])
    except getopt.error, msg:
        print msg
        print "for help use --help"
        sys.exit(2)
    
    low = True
        
    # process options
    for o, a in opts:
        if o in ("-h", "--help"):
            print __doc__
            sys.exit(0)
        if o in ("--low"):
            low = True
        if o in ("--high"):
            low = False
    # process arguments
    for arg in args:
        process(low, arg)

if __name__ == "__main__":
    main()

