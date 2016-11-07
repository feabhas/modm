#!/usr/bin/env python2
# -*- coding: utf-8 -*-
#
# Copyright (c) 2009-2012, Fabian Greif
# Copyright (c) 2009-2010, 2014, Martin Rosekeit
# Copyright (c) 2010, Georgi Grinshpun
# Copyright (c) 2011-2015, Niklas Hauser
# Copyright (c) 2012-2013, 2015, Sascha Schade
# Copyright (c) 2013-2015, Kevin Laeufer
# Copyright (c) 2016, Daniel Krebs
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
# -----------------------------------------------------------------------------

import os
import platform

from SCons.Script import *

# -----------------------------------------------------------------------------
def generate(env, **kw):
	env['CXXCOM'] = []
	env['LINKCOM'] = []
	env['LIBS'] = []
	env['LIBPATH'] = []
	env['ENV'] = os.environ

	if env['HOSTED_DEVICE'] == 'linux':
		env['LIBS'] = ['boost_thread', 'boost_system', 'pthread']
	elif env['HOSTED_DEVICE'] == 'darwin':
		env['LIBS'] = ['boost_thread-mt', 'boost_system']

	if 'CC' in os.environ:
		c_compiler = os.environ['CC']
	else:
		c_compiler = 'gcc'

	if 'CXX' in os.environ:
		cpp_compiler = os.environ['CXX']
	else:
		cpp_compiler = 'g++'

	env.Append(ENV = {'PATH' : os.environ['PATH']})

	if platform.system() == 'Windows':
		env.Tool('mingw')
	else:
		env.Tool('gcc')
		env.Tool('g++')
		env.Tool('gnulink')
		env.Tool('ar')
		env.Tool('as')
		env['NM'] = "nm"
		env['SIZE'] = "du -s -h"
		env['CC'] = c_compiler
		env['CXX'] = cpp_compiler

	# build messages
	if ARGUMENTS.get('verbose') != '1':
		env['CCCOMSTR'] = "Compiling C: $TARGET"
		env['CXXCOMSTR'] = "Compiling C++: $TARGET"
		env['ASCOMSTR'] = "Assembling: $TARGET"
		env['ASPPCOMSTR'] = "Assembling: $TARGET"
		env['LINKCOMSTR'] = "Linking: $TARGET"
		env['RANLIBCOMSTR'] = "Indexing: $TARGET"
		env['ARCOMSTR'] = "Create Library: $TARGET"

		env['SIZECOMSTR'] = "Size after:"
		env['SYMBOLSCOMSTR'] = "Show symbols for '$SOURCE':"

	# flags for C and C++
	env['CCFLAGS'] = [
		"-funsigned-char",
		"-Wall",
		"-Wextra",
		"-Wundef",
		"-ggdb",
		"-DBASENAME=${SOURCE.file}",
		"$OPTIMIZATION",
	]
	env['CCFLAGS'] += env['XPCC_ADDITIONAL_CCFLAGS']

	#if c_compiler == 'clang':
	#	env['CCFLAGS'].append("-funsigned-bitfields")

	# C++ flags
	env['CXXFLAGS'] = [
		"-std=c++11",
#		"-Weffc++",
		"-Woverloaded-virtual",
	]

	if 'CXXFLAGS' in os.environ:
		flags = "".join(os.environ['CXXFLAGS'])
		env['CXXFLAGS'].append(flags)
	if 'LDFLAGS' in os.environ:
		flags = "".join(os.environ['LDFLAGS'])
		env['LINKFLAGS'] = flags

	# required for __attribute__((packed))
	if platform.system() == 'Windows':
		env['CXXFLAGS'].append("-mno-ms-bitfields")

def exists(env):
	return env.Detect('g++')
