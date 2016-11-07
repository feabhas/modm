/*
 * Copyright (c) 2009-2011, Fabian Greif
 * Copyright (c) 2009-2010, Martin Rosekeit
 * Copyright (c) 2011-2014, Niklas Hauser
 * Copyright (c) 2012, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_UI_RGB_LED_HPP
#define XPCC_UI_RGB_LED_HPP

#include <stdint.h>
#include "led.hpp"
#include "../color.hpp"

namespace xpcc
{

namespace ui
{

/**
 * Group three LEDs into a RGB controller
 *
 * @todo add RGB specific functions to this class.
 *
 * @author	Niklas Hauser
 * @ingroup led
 */
class RgbLed
{
	Led& red;
	Led& green;
	Led& blue;

	::xpcc::color::Rgb absolute;

public:
	RgbLed(Led& red, Led& green, Led& blue)
	:	red(red), green(green), blue(blue), absolute()
	{
	}

	inline void
	setColor(::xpcc::color::Rgb color)
	{
		absolute = color;

		red.setBrightness(absolute.red);
		green.setBrightness(absolute.green);
		blue.setBrightness(absolute.blue);
	}

	inline void
	setColor(::xpcc::color::Hsv color)
	{
		color.toRgb(&absolute);
		setColor(absolute);
	}

	inline ::xpcc::color::Rgb
	getColor()
	{
		return ::xpcc::color::Rgb(
			red.getBrightness(),
			green.getBrightness(),
			blue.getBrightness()
		);
	}

	inline bool
	isFading()
	{
		return (red.isFading() ||
				green.isFading() ||
				blue.isFading());
	}

	inline void
	fadeTo(::xpcc::color::Rgb color, uint16_t time)
	{
		absolute = color;

		red.fadeTo(absolute.red, time);
		green.fadeTo(absolute.green, time);
		blue.fadeTo(absolute.blue, time);
	}

	inline void
	fadeTo(::xpcc::color::Hsv color, uint16_t time)
	{
		color.toRgb(&absolute);
		fadeTo(absolute, time);
	}

	/// should be called every 1ms or more.
	inline void
	update()
	{
		red.update();
		green.update();
		blue.update();
	}
};

}

}

#endif	// XPCC__PWM_RGB_LED_HPP
