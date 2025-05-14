#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include <string>
#include <sstream>
#include "DateTime.hpp"

#define DASH " - "

enum logLevel
{
	NOTICE,
	WARNING,
	ERROR,
	INFO,
	DEBUG
};

class Logger
{
public:
	Logger(logLevel l)
	{
		m_name = "";
		m_level = l;
	}

	Logger(const std::string log_name, logLevel l)
	{
		m_name = "[" + log_name + "]";
		m_level = l;
	}

	void setLogLevel(logLevel l)
	{
		debug("Changed logLevel from " + getLogLevelAsString(m_level) + " to " + getLogLevelAsString(l));
		m_level = l;
	}

	template<typename... Args>
	void notice(const Args&... args)
	{
		if (m_level < logLevel::NOTICE)
			return;

		std::string msg = formatArgsToString(args...);
		prepareOutput(msg, logLevel::NOTICE);
	}

	template<typename... Args>
	void warning(const Args&... args)
	{
		if (m_level < logLevel::WARNING)
			return;

		std::string msg = formatArgsToString(args...);
		prepareOutput(msg, logLevel::WARNING);
	}

	template<typename... Args>
	void error(const Args&... args)
	{
		if (m_level < logLevel::ERROR)
			return;

		std::string msg = formatArgsToString(args...);
		prepareOutput(msg, logLevel::ERROR);
	}

	template<typename... Args>
	void info(const Args&... args)
	{
		if (m_level < logLevel::INFO)
			return;

		std::string msg = formatArgsToString(args...);
		prepareOutput(msg, logLevel::INFO);
	}

	template<typename... Args>
	void debug(const Args&... args)
	{
		if (m_level < logLevel::DEBUG)
			return;

		std::string msg = formatArgsToString(args...);
		prepareOutput(msg, logLevel::DEBUG);
	}
private:
	std::string m_name;
	std::stringstream m_ss;
	logLevel m_level;
	DateTime m_dateTime;

	void prepareOutput(const std::string& s, logLevel level)
	{
		appendToBuffer(m_dateTime.getCurrentDateTime());
		appendToBuffer(DASH);
		appendToBuffer(getLogLevelAsString(level));

		if (!m_name.empty())
		{
			appendToBuffer(DASH);
			appendToBuffer(m_name);
		}

		appendToBuffer(DASH);
		appendToBuffer(s);

		logOutput();
	}

	std::string getLogLevelAsString(logLevel l)
	{
		switch (l)
		{
			case logLevel::DEBUG:
				return "DEBUG";
			case logLevel::INFO:
				return "INFO";
			case logLevel::ERROR:
				return "ERROR";
			case logLevel::WARNING:
				return "WARNING";
			case logLevel::NOTICE:
				return "NOTICE";
		}

		return "";
	}

	void appendToBuffer(const std::string& s)
	{
		m_ss << s;
	}

	void clearBuffer()
	{
		m_ss.str("");
		m_ss.clear();
	}

	void logOutput()
	{
		std::cout << m_ss.str() << std::endl;
		clearBuffer();
	}

	template<typename... Args>
	std::string formatArgsToString(const Args&... args) 
	{
		std::ostringstream oss;
		(oss << ... << args);  
		return oss.str();
	}
};

#endif
