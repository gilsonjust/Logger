#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include <string>
#include <sstream>
#include "DateTime.hpp"

#define DASH_SEP " - "
#define LEFT_BRACKET "["
#define RIGHT_BRACKET "]"

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
		m_log_name = "";
		m_level = l;
	}

	Logger(const std::string log_name, logLevel l)
	{
		m_log_name = LEFT_BRACKET + log_name + RIGHT_BRACKET;
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

		std::string text = formatArgsToString(args...);
		prepareOutput(text, logLevel::NOTICE);
	}

	template<typename... Args>
	void warning(const Args&... args)
	{
		if (m_level < logLevel::WARNING)
			return;

		std::string text = formatArgsToString(args...);
		prepareOutput(text, logLevel::WARNING);
	}

	template<typename... Args>
	void error(const Args&... args)
	{
		if (m_level < logLevel::ERROR)
			return;

		std::string text = formatArgsToString(args...);
		prepareOutput(text, logLevel::ERROR);
	}

	template<typename... Args>
	void info(const Args&... args)
	{
		if (m_level < logLevel::INFO)
			return;

		std::string text = formatArgsToString(args...);
		prepareOutput(text, logLevel::INFO);
	}

	template<typename... Args>
	void debug(const Args&... args)
	{
		if (m_level < logLevel::DEBUG)
			return;

		std::string text = formatArgsToString(args...);
		prepareOutput(text, logLevel::DEBUG);
	}
private:
	template<typename... Args>
	std::string formatArgsToString(const Args&... args)
	{
		std::ostringstream text;
		(text << ... << args);
		return text.str();
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

	void appendToBuffer(const std::string& text)
	{
		m_output_stream << text;
	}

	void clearBuffer()
	{
		m_output_stream.str("");
		m_output_stream.clear();
	}

	void logOutput()
	{
		std::cout << m_output_stream.str() << std::endl;
		clearBuffer();
	}

	void prepareOutput(const std::string& text, logLevel level)
	{
		appendToBuffer(DateTime::getCurrentDateTime() + DASH_SEP + getLogLevelAsString(level));

		if (!m_log_name.empty())
			appendToBuffer(DASH_SEP + m_log_name);

		appendToBuffer(DASH_SEP + text);

		logOutput();
	}

private:
	std::string m_log_name;
	std::stringstream m_output_stream;
	logLevel m_level;
};

#endif
