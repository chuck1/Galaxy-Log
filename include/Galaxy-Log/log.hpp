#ifndef GALAXY_LOG_LOG_HPP
#define GALAXY_LOG_LOG_HPP

/*
 *  *          Copyright Andrey Semashev 2007 - 2013.
 *   * Distributed under the Boost Software License, Version 1.0.
 *    *    (See accompanying file LICENSE_1_0.txt or copy at
 *     *          http://www.boost.org/LICENSE_1_0.txt)
 *      */

#include <cstddef>
#include <iostream>


enum severity_level {
	debug,
	info,
	warning,
	error,
	critical
};

namespace gal {
	namespace log {
		void		init();
	}
}

inline std::ostream& operator<< (std::ostream& strm, severity_level level) {
	static const char* strings[] =
	{
		"debug",
		"info",
		"warning",
		"error",
		"critical"
	};

	if (static_cast< std::size_t >(level) < sizeof(strings) / sizeof(*strings))
		strm << strings[level];
	else
		strm << static_cast< int >(level);

	return strm;
}

// disable slow boost logging

#define BOOST_LOG_CHANNEL_SEV(log,chan,sev) if(sev >= info) std::cout

#define GAL_LOG_ENDLINE std::endl

#endif



