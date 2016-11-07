/*
 * Copyright (c) 2009, Martin Rosekeit
 * Copyright (c) 2009-2011, Fabian Greif
 * Copyright (c) 2012, 2015, Niklas Hauser
 * Copyright (c) 2015, Georgi Grinshpun
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

/**
 * \defgroup architecture	Architecture
 * 
 * Supported platforms
 */

#ifndef XPCC__ARCHITECTURE_HPP
#define XPCC__ARCHITECTURE_HPP

// platform.hpp is hidden in 'generated_platform_xx/include_platform_hack'. See platform_tools.py
// The folder will be included in CPPPATH, so for everyone it is still available as usual like this:
#include <xpcc/architecture/platform.hpp>
#include "architecture/driver.hpp"

#endif	// XPCC__ARCHITECTURE_HPP
