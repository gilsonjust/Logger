#include "Logger.hpp"

int main()
{
	Logger log("Logger", logLevel::L_DEBUG);

	LOG_NOTICE(log, "notice log");
	LOG_ERROR(log, "logger error", 123);
	LOG_WARN(log, "logger warning", 123123, " abc ", 321);
	LOG_INFO(log, "logger info", 321);
	LOG_DEBUG(log, "Test: ", 123);

	return EXIT_SUCCESS;
}