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
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

enum severity_level {
	debug,
	info,
	warning,
	error,
	critical
};

namespace gal {
	namespace log {

		typedef expr::channel_severity_filter_actor< std::string, severity_level >	min_severity_filter;

		typedef src::severity_channel_logger< severity_level, std::string >		logger_type;


		extern min_severity_filter	min_severity;
		extern logger_type		lg;

		void		init();
	}
}

// Define the attribute keywords
BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(channel, "Channel", std::string)

std::ostream& operator<< (std::ostream& strm, severity_level level);

// disable slow boost logging

#undef BOOST_LOG_CHANNEL_SEV
#define BOOST_LOG_CHANNEL_SEV(log,chan,sev) if(sev >= info) std::cout

#define GAL_LOG_ENDLINE std::endl


#endif



