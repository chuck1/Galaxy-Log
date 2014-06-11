#ifndef GALAXY_LOG_LOG_HPP
#define GALAXY_LOG_LOG_HPP

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

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id,    "LineID",       unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity,   "Severity",     severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(channel,    "Channel",      std::string)

namespace gal {
	namespace log {
		typedef expr::channel_severity_filter_actor< ::std::string, severity_level >		min_severity_filter;

		extern min_severity_filter	min_severity;

		void		init();
		void		refresh();

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

typedef src::severity_channel_logger< severity_level, std::string > logger_type;

extern logger_type lg;

#endif



