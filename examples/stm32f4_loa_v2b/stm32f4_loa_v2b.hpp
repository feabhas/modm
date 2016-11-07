/*
 * Copyright (c) 2013, Kevin Laeufer
 * Copyright (c) 2014, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

//
// Loa Board v2b
// STM32F4 and Spartan FPGA
// https://github.com/dergraaf/loa
//

#ifndef XPCC_STM32_F4_LOA_V2B_HPP
#define XPCC_STM32_F4_LOA_V2B_HPP

using namespace xpcc::stm32;

typedef GpioOutputE5 LedWhite;
typedef GpioOutputE6 LedGreen;

/// STM32F4 running at 168MHz (USB Clock at 48MHz) generated from the
/// external on-board 25MHz oscillator
typedef SystemClock<Pll<ExternalClock<MHz25>, MHz168, MHz48> > defaultSystemClock;

#endif	// XPCC_STM32_F4_LOA_V2B_HPP
