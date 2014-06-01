#include <cstddef>
#include <iostream>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <Galaxy-Log/log.hpp>

std::ostream& operator<< (std::ostream& strm, severity_level level) {
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

gal::log::min_severity_filter gal::log::min_severity = expr::channel_severity_filter(channel, severity);
gal::log::logger_type gal::log::lg;


void		gal::log::init() {

	std::cout << "initializer" << std::endl;

	logging::add_console_log
		(
		 std::clog,
		 keywords::filter = min_severity || severity >= critical,
		 keywords::format =
		 (
		  expr::stream
		  << line_id
		  << ": <" << severity
		  << "> [" << channel << "] "
		  << expr::smessage
		 )
		);

	logging::add_common_attributes();
}



