/*
 * Copyright (c) 2009-2012, Fabian Greif
 * Copyright (c) 2009-2010, Martin Rosekeit
 * Copyright (c) 2012-2013, Niklas Hauser
 * Copyright (c) 2013, 2015, Sascha Schade
 * Copyright (c) 2013, Kevin Laeufer
 * Copyright (c) 2014, Daniel Krebs
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_FONT__FIXED_WIDTH_5X8_HPP
#define	XPCC_FONT__FIXED_WIDTH_5X8_HPP

#include <xpcc/architecture/driver/accessor.hpp>

namespace xpcc
{
	namespace font
	{
		/**
		 * \brief	Fixed Width 5x8
		 * 
		 * - fixed width     : 5
		 * - height          : 8
		 * - hspace          : 0
		 * - vspace          : 1
		 * - first char      : 32
		 * - last char       : 128
		 * - number of chars : 96
		 * - size in bytes   : 584
		 * 
		 * \ingroup	font
		 */
		EXTERN_FLASH_STORAGE(uint8_t FixedWidth5x8[]);
	}
}

#endif	// XPCC_FONT__FIXED_WIDTH_5X8_HPP

