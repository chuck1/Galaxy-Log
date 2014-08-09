#include <gal/log/log.hpp>

void test_logging(std::string const& channel_name) {
	
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, info) << "A notification severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, warning) << "A warning severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, error) << "An error severity level message";
	BOOST_LOG_CHANNEL_SEV(lg, channel_name, critical) << "A critical severity level message";
}

int main(int ac, char** av) {

	gal::log::init();

	gal::log::min_severity["general"] = debug;

	gal::log::refresh();	

	test_logging("general");
	test_logging("network");
	test_logging("gui");
	test_logging("filesystem");

	return 0;

}


