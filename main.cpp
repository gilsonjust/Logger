#include <iostream>
#include "Logger.hpp"

int main()
{
	Logger log("main", logLevel::DEBUG);

	log.debug("debug ", 123);
	log.error("error");
	log.info("info");
	log.warning("warning", " teste2");
	log.notice("notice");

	log.setLogLevel(logLevel::WARNING);

	log.debug("debug");
	log.error("error");
	log.info("info");
	log.warning("warning");
	log.notice("notice");

	return EXIT_SUCCESS;
}