/*
 * Copyright (c) 2009-2010, Martin Rosekeit
 * Copyright (c) 2009-2011, Fabian Greif
 * Copyright (c) 2012-2014, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef FAKE_CAN_DRIVER_HPP
#define FAKE_CAN_DRIVER_HPP

#include <xpcc/container/linked_list.hpp>
#include <xpcc/architecture/interface/can.hpp>

class FakeCanDriver : public xpcc::Can
{
public:
	FakeCanDriver();
	
	bool
	isMessageAvailable();
	
	bool
	getMessage(xpcc::can::Message& message);
	
	bool
	isReadyToSend();
	
	bool
	sendMessage(const xpcc::can::Message& message);

	static uint8_t
	getReceiveErrorCounter();

	static uint8_t
	getTransmitErrorCounter();

	static BusState
	getBusState();
	
public:
	/// Messages which should be received
	xpcc::LinkedList<xpcc::can::Message> receiveList;
	
	/// List of all messages send
	xpcc::LinkedList<xpcc::can::Message> sendList;
	
	/// number of messages which could be send
	uint8_t sendSlots;
};

#endif	// FAKE_CAN_DRIVER_HPP
