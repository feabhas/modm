#!/usr/bin/env pythonNone
# -*- coding: utf-8 -*-
#
# Copyright (c) 2014, Niklas Hauser
# Copyright (c) 2016, Fabian Greif
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
# -----------------------------------------------------------------------------

mcu = \
[
	{"device": "at32uc3a0512", "mcu": "uc3a0512"},
	{"device": "at90can128", "mcu": "c128"},
	{"device": "at90can32", "mcu": "c32"},
	{"device": "at90can64", "mcu": "c64"},
	{"device": "at90pwm2", "mcu": "pwm2"},
	{"device": "at90pwm2b", "mcu": "pwm2b"},
	{"device": "at90pwm3", "mcu": "pwm3"},
	{"device": "at90pwm316", "mcu": "pwm316"},
	{"device": "at90pwm3b", "mcu": "pwm3b"},
	{"device": "at90s1200", "mcu": "1200"},
	{"device": "at90s2313", "mcu": "2313"},
	{"device": "at90s2333", "mcu": "2333"},
	{"device": "at90s2343", "mcu": "2343"},
	{"device": "at90s4414", "mcu": "4414"},
	{"device": "at90s4433", "mcu": "4433"},
	{"device": "at90s4434", "mcu": "4434"},
	{"device": "at90s8515", "mcu": "8515"},
	{"device": "at90s8535", "mcu": "8535"},
	{"device": "at90usb1286", "mcu": "usb1286"},
	{"device": "at90usb1287", "mcu": "usb1287"},
	{"device": "at90usb162", "mcu": "usb162"},
	{"device": "at90usb646", "mcu": "usb646"},
	{"device": "at90usb647", "mcu": "usb647"},
	{"device": "at90usb82", "mcu": "usb82"},
	{"device": "atmega103", "mcu": "m103"},
	{"device": "atmega128", "mcu": "m128"},
	{"device": "atmega1280", "mcu": "m1280"},
	{"device": "atmega1281", "mcu": "m1281"},
	{"device": "atmega1284p", "mcu": "m1284p"},
	{"device": "atmega1284rfr2", "mcu": "m1284rfr2"},
	{"device": "atmega128rfa1", "mcu": "m128rfa1"},
	{"device": "atmega128rfr2", "mcu": "m128rfr2"},
	{"device": "atmega16", "mcu": "m16"},
	{"device": "atmega161", "mcu": "m161"},
	{"device": "atmega162", "mcu": "m162"},
	{"device": "atmega163", "mcu": "m163"},
	{"device": "atmega164p", "mcu": "m164p"},
	{"device": "atmega168", "mcu": "m168"},
	{"device": "atmega168p", "mcu": "m168p"},
	{"device": "atmega169", "mcu": "m169"},
	{"device": "atmega16u2", "mcu": "m16u2"},
	{"device": "atmega2560", "mcu": "m2560"},
	{"device": "atmega2561", "mcu": "m2561"},
	{"device": "atmega2564rfr2", "mcu": "m2564rfr2"},
	{"device": "atmega256rfr2", "mcu": "m256rfr2"},
	{"device": "atmega32", "mcu": "m32"},
	{"device": "atmega324p", "mcu": "m324p"},
	{"device": "atmega324pa", "mcu": "m324pa"},
	{"device": "atmega325", "mcu": "m325"},
	{"device": "atmega3250", "mcu": "m3250"},
	{"device": "atmega328", "mcu": "m328"},
	{"device": "atmega328p", "mcu": "m328p"},
	{"device": "atmega329", "mcu": "m329"},
	{"device": "atmega3290", "mcu": "m3290"},
	{"device": "atmega3290p", "mcu": "m3290p"},
	{"device": "atmega329p", "mcu": "m329p"},
	{"device": "atmega32u2", "mcu": "m32u2"},
	{"device": "atmega32u4", "mcu": "m32u4"},
	{"device": "atmega406", "mcu": "m406"},
	{"device": "atmega48", "mcu": "m48"},
	{"device": "atmega48p", "mcu": "m48p"},
	{"device": "atmega64", "mcu": "m64"},
	{"device": "atmega640", "mcu": "m640"},
	{"device": "atmega644", "mcu": "m644"},
	{"device": "atmega644p", "mcu": "m644p"},
	{"device": "atmega644rfr2", "mcu": "m644rfr2"},
	{"device": "atmega645", "mcu": "m645"},
	{"device": "atmega6450", "mcu": "m6450"},
	{"device": "atmega649", "mcu": "m649"},
	{"device": "atmega6490", "mcu": "m6490"},
	{"device": "atmega64rfr2", "mcu": "m64rfr2"},
	{"device": "atmega8", "mcu": "m8"},
	{"device": "atmega8515", "mcu": "m8515"},
	{"device": "atmega8535", "mcu": "m8535"},
	{"device": "atmega88", "mcu": "m88"},
	{"device": "atmega88p", "mcu": "m88p"},
	{"device": "atmega8u2", "mcu": "m8u2"},
	{"device": "attiny10", "mcu": "t10"},
	{"device": "attiny11", "mcu": "t11"},
	{"device": "attiny12", "mcu": "t12"},
	{"device": "attiny13", "mcu": "t13"},
	{"device": "attiny15", "mcu": "t15"},
	{"device": "attiny1634", "mcu": "t1634"},
	{"device": "attiny20", "mcu": "t20"},
	{"device": "attiny2313", "mcu": "t2313"},
	{"device": "attiny24", "mcu": "t24"},
	{"device": "attiny25", "mcu": "t25"},
	{"device": "attiny26", "mcu": "t26"},
	{"device": "attiny261", "mcu": "t261"},
	{"device": "attiny4", "mcu": "t4"},
	{"device": "attiny40", "mcu": "t40"},
	{"device": "attiny4313", "mcu": "t4313"},
	{"device": "attiny43u", "mcu": "t43u"},
	{"device": "attiny44", "mcu": "t44"},
	{"device": "attiny45", "mcu": "t45"},
	{"device": "attiny461", "mcu": "t461"},
	{"device": "attiny5", "mcu": "t5"},
	{"device": "attiny84", "mcu": "t84"},
	{"device": "attiny85", "mcu": "t85"},
	{"device": "attiny861", "mcu": "t861"},
	{"device": "attiny88", "mcu": "t88"},
	{"device": "attiny9", "mcu": "t9"},
	{"device": "atxmega128a1", "mcu": "x128a1"},
	{"device": "atxmega128a1revd", "mcu": "x128a1d"},
	{"device": "atxmega128a1u", "mcu": "128a1u"},
	{"device": "atxmega128a3", "mcu": "x128a3"},
	{"device": "atxmega128a3u", "mcu": "x128a3u"},
	{"device": "atxmega128a4", "mcu": "x128a4"},
	{"device": "atxmega128a4u", "mcu": "x128a4u"},
	{"device": "atxmega128b1", "mcu": "x128b1"},
	{"device": "atxmega128b3", "mcu": "x128b3"},
	{"device": "atxmega128c3", "mcu": "x128c3"},
	{"device": "atxmega128d3", "mcu": "x128d3"},
	{"device": "atxmega128d4", "mcu": "x128d4"},
	{"device": "atxmega16a4", "mcu": "x16a4"},
	{"device": "atxmega16a4u", "mcu": "x16a4u"},
	{"device": "atxmega16c4", "mcu": "x16c4"},
	{"device": "atxmega16d4", "mcu": "x16d4"},
	{"device": "atxmega16e5", "mcu": "x16e5"},
	{"device": "atxmega192a1", "mcu": "x192a1"},
	{"device": "atxmega192a3", "mcu": "x192a3"},
	{"device": "atxmega192a3u", "mcu": "x192a3u"},
	{"device": "atxmega192c3", "mcu": "x192c3"},
	{"device": "atxmega192d3", "mcu": "x192d3"},
	{"device": "atxmega256a1", "mcu": "x256a1"},
	{"device": "atxmega256a3", "mcu": "x256a3"},
	{"device": "atxmega256a3b", "mcu": "x256a3b"},
	{"device": "atxmega256a3bu", "mcu": "x256a3bu"},
	{"device": "atxmega256a3u", "mcu": "x256a3u"},
	{"device": "atxmega256c3", "mcu": "x256c3"},
	{"device": "atxmega256d3", "mcu": "x256d3"},
	{"device": "atxmega32a4", "mcu": "x32a4"},
	{"device": "atxmega32a4u", "mcu": "x32a4u"},
	{"device": "atxmega32c4", "mcu": "x32c4"},
	{"device": "atxmega32d4", "mcu": "x32d4"},
	{"device": "atxmega32e5", "mcu": "x32e5"},
	{"device": "atxmega384c3", "mcu": "x384c3"},
	{"device": "atxmega384d3", "mcu": "x384d3"},
	{"device": "atxmega64a1", "mcu": "x64a1"},
	{"device": "atxmega64a1u", "mcu": "x64a1u"},
	{"device": "atxmega64a3", "mcu": "x64a3"},
	{"device": "atxmega64a3u", "mcu": "x64a3u"},
	{"device": "atxmega64a4", "mcu": "x64a4"},
	{"device": "atxmega64a4u", "mcu": "x64a4u"},
	{"device": "atxmega64b1", "mcu": "x64b1"},
	{"device": "atxmega64b3", "mcu": "x64b3"},
	{"device": "atxmega64c3", "mcu": "x64c3"},
	{"device": "atxmega64d3", "mcu": "x64d3"},
	{"device": "atxmega64d4", "mcu": "x64d4"},
	{"device": "atxmega8e5", "mcu": "x8e5"}
]
