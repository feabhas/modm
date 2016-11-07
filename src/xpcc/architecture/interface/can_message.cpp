/*
 * Copyright (c) 2015-2016, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xpcc/io/iostream.hpp>
#include <xpcc/architecture/utils.hpp>
#include <xpcc/architecture/interface/can_message.hpp>

namespace xpcc
{

namespace can
{

xpcc::IOStream&
operator << (xpcc::IOStream& s, const xpcc::can::Message m)
{
    s.printf("id = %04x, len = ", m.identifier);
    s << m.length;
    s.printf(", flags = %c%c, data = ",
             m.flags.rtr ? 'R' : 'r',
             m.flags.extended ? 'E' : 'e');
    for (uint_fast8_t ii = 0; ii < m.length; ++ii) {
        s.printf("%02x ", m.data[ii]);
    }
    return s;
}

bool
xpcc::can::Message::operator == (const xpcc::can::Message& rhs) const
{
	if ((this->identifier     == rhs.identifier) and
		(this->length         == rhs.length)     and
		(this->flags.rtr      == rhs.flags.rtr)  and
		(this->flags.extended == rhs.flags.extended))
	{
		bool eq = true;
		for (uint8_t ii = 0; ii < this->length; ++ii)
		{
			if (this->data[ii] != rhs.data[ii]) {
				eq = false;
			}
		}
		return eq;
	}
	return false;
}
} // can namespace
} // xpcc namespace
