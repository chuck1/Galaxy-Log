#include <gal/log/log.hpp>

void test_logging(severity_level chan) {
	LOG(lg, chan, info) << "A notification severity level message";
	LOG(lg, chan, warning) << "A warning severity level message";
	LOG(lg, chan, error) << "An error severity level message";
	LOG(lg, chan, critical) << "A critical severity level message";
}

int main(int ac, char** av) {

	/*
	test_logging("general");
	test_logging("network");
	test_logging("gui");
	test_logging("filesystem");
	*/
	return 0;

}


