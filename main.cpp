#include "Logger.hpp"

int main()
{
	Logger log("main", logLevel::L_DEBUG);

	Logger::setTextColor(logColor::C_NORMAL);

	log.debug("debug ", 123);
	log.error("error");
	log.info("info");

	Logger::setTextColor(logColor::C_RED);
	log.warning("warning", " teste2");
	log.notice("notice");

	log.setLogLevel(logLevel::L_ERROR);

	Logger::setTextColor(logColor::C_GREEN);

	log.debug("debug");
	log.error("error");
	log.info("info");

	Logger::setTextColor(logColor::C_BLUE);
	log.warning("warning");
	log.notice("notice");

	log.newLine(1);
	log.newLine(0);

	Logger::setTextColor(logColor::C_RED);

	Logger otherLog("error", logLevel::L_INFO);

	Logger::setTextColor(logColor::C_YELLOW);

	otherLog.error("Error test log");
	otherLog.debug("Debug test log");

	otherLog.setLogLevel(logLevel::L_ERROR);
	otherLog.info("Info test log");

	otherLog.newLine(3);

	log.setLogLevel(logLevel::L_INFO);

	Logger::setTextColor(logColor::C_RED);

	log.error("GEJ: ", 0);
	log.error("GEJ: ", 1);
	log.error("GEJ: ", 2);

	Logger::setTextColor(logColor::C_NORMAL);

	log.newLine(4);

	return EXIT_SUCCESS;
}