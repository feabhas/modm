/*
 * Copyright (c) 2009-2010, Fabian Greif
 * Copyright (c) 2010, Martin Rosekeit
 * Copyright (c) 2012, Sascha Schade
 * Copyright (c) 2012, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <xpcc/math/utils/misc.hpp>

#include "angle.hpp"

// ----------------------------------------------------------------------------
float
xpcc::Angle::normalize(float angle)
{
	if (isPositive(angle))
	{
		while (angle > M_PI) {
			angle -= 2 * M_PI;
		}
	}
	else {
		while (angle < -M_PI) {
			angle += 2 * M_PI;
		}
	}
	
	return angle;
}

// ----------------------------------------------------------------------------
float
xpcc::Angle::reverse(float angle)
{
	if (isPositive(angle))
	{
		angle -= M_PI;
	}
	else {
		angle += M_PI;
	}
	
	return angle;
}

// ----------------------------------------------------------------------------
float
xpcc::Angle::perpendicular(float angle, const bool cw)
{
	if (cw)
	{
		angle = xpcc::Angle::normalize(angle - M_PI_2);
	}
	else {
		angle = xpcc::Angle::normalize(angle + M_PI_2);
	}

	return angle;
}
