#include "Logger.hpp"

int main()
{
	Logger log("Logger", logLevel::L_DEBUG);

	LOG_NOTICE(log, "notice log");
	LOG_ERROR(log, "logger error", 123);
	LOG_WARN(log, "logger warning", 123123, " abc ", 321);
	LOG_INFO(log, "logger info", 321);
	LOG_DEBUG(log, "Test: ", 123);

	Logger app("App", logLevel::L_INFO);

	LOG_INFO(app, "teste application log", 123123);
	LOG_NOTICE(app, "teste application NOTICE log");

	for (int i = 0; i < 10; i++)
		LOG_INFO(app, i);

	LOG_DEBUG(log, "Exiting application");

	return EXIT_SUCCESS;
}