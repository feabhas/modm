/*
 * Copyright (c) 2009-2011, Fabian Greif
 * Copyright (c) 2012, Sascha Schade
 * Copyright (c) 2015, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <xpcc/debug/logger.hpp>

// set new log level
#undef XPCC_LOG_LEVEL
#define	XPCC_LOG_LEVEL xpcc::log::DEBUG

#include "communication/identifier.hpp"
#include "communication/packets.hpp"

#include "sender.hpp"

// ----------------------------------------------------------------------------
component::Sender::Sender(uint8_t id, xpcc::Dispatcher &communication) :
	xpcc::AbstractComponent(id, communication),
	positionCallback(this, &Sender::getPositionCallback),
	timer(2000)
{
}

// ----------------------------------------------------------------------------
void
component::Sender::getPositionCallback(const xpcc::Header&,
		const robot::packet::Position *parameter)
{
	XPCC_LOG_INFO << XPCC_FILE_INFO
			<< "get position callback: x=" << parameter->x
			<< ", y=" << parameter->y << xpcc::endl;
}

// ----------------------------------------------------------------------------
void
component::Sender::update()
{
	if (timer.execute())
	{
		XPCC_LOG_INFO << XPCC_FILE_INFO << "sender update" << xpcc::endl;
		
		robot::packet::Position position(10, 20);
		
		this->callAction(
				robot::component::RECEIVER,
				robot::action::SET_POSITION,
				position);
		
		this->callAction(
				robot::component::RECEIVER,
				robot::action::GET_POSITION,
				positionCallback);
	}
}
