Simple logger C++ class

#include "Logger.hpp"

int main()
{
	Logger log("Logger", logLevel::L_DEBUG);

	LOG_ERROR(log, "Log error", 123);
	LOG_WARN(log, "Log warning", 321);
	LOG_NOTICE(log, "Log notice", 123123);
	LOG_INFO(log, "Log info");
	LOG_DEBUG(log, "Log debug", 321321321);

	for (int i = 0; i < 10; i++)
		LOG_INFO(log, i);

	Logger app("App", logLevel::L_DEBUG);

	LOG_ERROR(app, "Log error", 123);
	LOG_WARN(app, "Log warning", 321);
	LOG_NOTICE(app, "Log notice", 123123);
	LOG_INFO(app, "Log info");
	LOG_DEBUG(app, "Log debug", 321321321);

	for (int i = 0; i < 10; i++)
		LOG_INFO(app, i);

	return EXIT_SUCCESS;
}

![image](https://github.com/user-attachments/assets/d40135bc-475b-417b-98a0-e82209cb2e8b)
