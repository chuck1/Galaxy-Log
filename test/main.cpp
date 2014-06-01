#include <Galaxy-Log/log.hpp>
/*
void test_logging(logger_type& lg, std::string const& channel_name)
{
	
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, notification) << "A notification severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, warning) << "A warning severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, error) << "An error severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, critical) << "A critical severity level message";
}
*/
int main(int ac, char** av) {

	gal::log::min_severity["general"] = info;

	gal::log::init();
	
	BOOST_LOG_CHANNEL_SEV(gal::log::lg, "general", info) << "A normal severity level message" << GAL_LOG_ENDLINE;
	BOOST_LOG_CHANNEL_SEV(gal::log::lg, "general", debug) << "A debug severity level message" << GAL_LOG_ENDLINE;

/*	test_logging(lg, "general");
	test_logging(lg, "network");
	test_logging(lg, "gui");
	test_logging(lg, "filesystem");
*/

	return 0;

}


