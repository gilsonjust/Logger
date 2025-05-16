#include "Logger.hpp"

int main()
{
	Logger log("main", logLevel::DEBUG);

	log.debug("debug ", 123);
	log.error("error");
	log.info("info");
	log.warning("warning", " teste2");
	log.notice("notice");

	log.setLogLevel(logLevel::ERROR);

	log.debug("debug");
	log.error("error");
	log.info("info");
	log.warning("warning");
	log.notice("notice");

	log.newLine(1);
	log.newLine(0);

	Logger otherLog("error", logLevel::INFO);

	otherLog.error("Error test log");
	otherLog.debug("Debug test log");

	otherLog.setLogLevel(logLevel::ERROR);
	otherLog.info("Info test log");

	otherLog.newLine(3);

	log.setLogLevel(logLevel::INFO);

	log.error("GEJ: ", 0);
	log.error("GEJ: ", 1);
	log.error("GEJ: ", 2);

	log.newLine(4);

	return EXIT_SUCCESS;
}