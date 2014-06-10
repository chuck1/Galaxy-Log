#include <Galaxy-Log/log.hpp>

gal::log::min_severity_filter		gal::log::min_severity = expr::channel_severity_filter(channel, severity);

logger_type				lg;

void		gal::log::init() {
	// Create a minimal severity table filter

	// Set up the minimum severity levels for different channels

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
}
void		gal::log::refresh() {
	logging::add_common_attributes();
}







