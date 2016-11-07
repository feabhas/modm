/*
 * Copyright (c) 2009-2011, Fabian Greif
 * Copyright (c) 2009, Thorsten Lajewski
 * Copyright (c) 2012-2014, 2016, Niklas Hauser
 * Copyright (c) 2012, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC__SIEMENS_M55_HPP
#define XPCC__SIEMENS_M55_HPP

#include <xpcc/architecture/driver/delay.hpp>

#include <xpcc/ui/display/buffered_graphic_display.hpp>

namespace xpcc
{
	/**
	 * \brief	Driver for Siemens M55 displays
	 *
	 * (also shared with A60, A65, C60, MC60 and S55 models)
	 *
	 * \ingroup	driver_display
	 */
	template <typename SPI, typename CS, typename RS, typename Reset>
	class SiemensM55 : public BufferedGraphicDisplay<101, 80>
	{
	public:
		void
		initialize();

		/**
		 * \brief	Update the display with the content of the RAM buffer
		 */
		virtual void
		update();

	private:
		xpcc_always_inline void
		lcdSettings(void);

		xpcc_always_inline void
		lcdCls(uint16_t colour);
	};
}

#include "siemens_m55_impl.hpp"

#endif // XPCC__SIEMENS_M55_HPP
