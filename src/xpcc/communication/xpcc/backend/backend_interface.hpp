/*
 * Copyright (c) 2009-2010, Fabian Greif
 * Copyright (c) 2009-2010, Martin Rosekeit
 * Copyright (c) 2009, Georgi Grinshpun
 * Copyright (c) 2012-2014, Niklas Hauser
 * Copyright (c) 2012-2013, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef	XPCC__BACKEND_INTERFACE_HPP
#define	XPCC__BACKEND_INTERFACE_HPP

#include <stdint.h>

#include "header.hpp"

/**
 * \ingroup		xpcc_comm
 * \defgroup 	backend Backend
 * \brief 		The backend provides connection to different hardware modules
 * 				to transmit the communication.
 *
 * All backend-implementations have to implement xpcc::BackendInterface.
 */

namespace xpcc
{
	/**
	 * \brief 		The BackendInterface provides a common interface for using
	 * 				different hardware modules to transmit messages.
	 *
	 * All backends have to implement this interface.
	 *
	 * \ingroup		xpcc_comm
	 * \author		Martin Rosekeit, Fabian Greif
	 */
	class BackendInterface
	{
	public:
		virtual
		~BackendInterface()
		{
		}

		virtual void
		update() = 0;

		/// Send a Message.
		virtual void
		sendPacket(const Header &header,
				SmartPointer payload = SmartPointer()) = 0;

		/// Check if a new packet was received by the backend
		virtual bool
		isPacketAvailable() const = 0;

		/// Access the packet.
		virtual const Header&
		getPacketHeader() const = 0;

		virtual const SmartPointer
		getPacketPayload() const = 0;

		virtual void
		dropPacket() = 0;
	};
}

#endif	// XPCC__BACKEND_INTERFACE_HPP
