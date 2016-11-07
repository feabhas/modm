/*
 * Copyright (c) 2015, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef	XPCC_COMMUNICATABLE_TASK_HPP
#define	XPCC_COMMUNICATABLE_TASK_HPP

#include "communicatable.hpp"
#include "communicator.hpp"

#include <xpcc/processing/task.hpp>

namespace xpcc
{

/**
 * A state-machine able to communicate via xpcc
 *
 * Needs to be part of a xpcc::AbstractComponent
 *
 * @see		xpcc::Task
 * @see		xpcc::Communicator
 * @see		xpcc::Communicatable
 *
 * @ingroup	xpcc_com
 * @author	Fabian Greif
 */
class CommunicatableTask : public Task, public Communicatable
{
public:
	CommunicatableTask(Communicator *parent) :
		parent(parent)
	{
	}

protected:
	Communicator *parent;
};

}	// namespace xpcc

#endif	// XPCC_COMMUNICATABLE_TASK_HPP
