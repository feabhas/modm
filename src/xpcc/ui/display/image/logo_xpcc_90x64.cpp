/*
 * Copyright (c) 2011, Fabian Greif
 * Copyright (c) 2013, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <xpcc/architecture/driver/accessor.hpp>

namespace bitmap
{
	FLASH_STORAGE(uint8_t logo_xpcc_90x64[]) =
	{
		90, 64,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x60, 0x20, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x20, 0x60, 0xc0, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1a, 0x22, 0xc2, 0x02, 0x02, 0x0c, 0x10, 0x20, 0x40, 0x20, 0x10, 0x0c, 0x02, 0x82, 0xc2, 0xf2, 0xfa, 0xfe, 0x1e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0x07, 0x01, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0x3e, 0x07, 0x03, 0x01, 0x80, 0xe0, 0x30, 0x18, 0x08, 0x08, 0x18, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x21, 0x12, 0x0c, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x04, 0x0e, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x80, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0x3c, 0x78, 0xe0, 0xc0, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x26, 0x21, 0x20, 0x20, 0x38, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xe0, 0xe0, 0xe1, 0xe7, 0xff, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x83, 0x80, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0x10, 0x10, 0x10, 0x18, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xe7, 0xd3, 0xf7, 0xff, 0xc7, 0xfb, 0xc7, 0xff, 0xcb, 0xc3, 0xff, 0xc1, 0xdb, 0xe7, 0xff, 0xe1, 0xdf, 0xff, 0xc5, 0xff, 0xc7, 0xfb, 0xc7, 0xff, 0x67, 0x5b, 0x83, 0xff, 0xff, 0xff, 0xc3, 0xfb, 0x3f, 0x18, 0x24, 0x18, 0x00, 0x3e, 0x24, 0x18, 0x00, 0x18, 0x24, 0x18, 0x00, 0x1e, 0x24, 0x00, 0x28, 0x24, 0x14,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	};
}

