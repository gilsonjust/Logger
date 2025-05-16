#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include <windows.h>
#include <string>
#include <sstream>
#include <iostream>
#include "DateTime.hpp"

#define DASH_SEP " - "
#define LEFT_BRACKET "["
#define RIGHT_BRACKET "]"

enum class logLevel
{
	L_NOTICE,
	L_WARNING,
	L_ERROR,
	L_INFO,
	L_DEBUG
};

enum class logColor
{
	C_GREEN,
	C_RED,
	C_BLUE,
	C_YELLOW,
	C_NORMAL
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

	logLevel getLogLevel() const
	{
		return m_level;
	}

	std::string getLoggerName() const
	{
		if (m_log_name.empty())
			return "";

		return m_log_name;
	}

	template<typename... Args>
	void notice(const Args&... args)
	{
		if (m_level < logLevel::L_NOTICE)
			return;

		std::string text = formatArgsToString(args...);
		prepareLogToOutput(text, logLevel::L_NOTICE);
	}

	template<typename... Args>
	void warning(const Args&... args)
	{
		if (m_level < logLevel::L_WARNING)
			return;

		std::string text = formatArgsToString(args...);
		prepareLogToOutput(text, logLevel::L_WARNING);
	}

	template<typename... Args>
	void error(const Args&... args)
	{
		if (m_level < logLevel::L_ERROR)
			return;

		std::string text = formatArgsToString(args...);
		prepareLogToOutput(text, logLevel::L_ERROR);
	}

	template<typename... Args>
	void info(const Args&... args)
	{
		if (m_level < logLevel::L_INFO)
			return;

		std::string text = formatArgsToString(args...);
		prepareLogToOutput(text, logLevel::L_INFO);
	}

	template<typename... Args>
	void debug(const Args&... args)
	{
		if (m_level < logLevel::L_DEBUG)
			return;

		std::string text = formatArgsToString(args...);
		prepareLogToOutput(text, logLevel::L_DEBUG);
	}

	void newLine(unsigned int lines)
	{
		if (lines == 0)
			return;

		for (unsigned int i = 0; i < lines; i++)
			logOutput();
	}

	static void setTextColor(logColor textColor)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (textColor)
		{
			case logColor::C_GREEN:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				break;
			case logColor::C_RED:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				break;
			case logColor::C_BLUE:
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				break;
			case logColor::C_YELLOW:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				break;
			case logColor::C_NORMAL:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			default:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
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
			case logLevel::L_DEBUG:
				return "DEBUG";
			case logLevel::L_INFO:
				return "INFO";
			case logLevel::L_ERROR:
				return "ERROR";
			case logLevel::L_WARNING:
				return "WARNING";
			case logLevel::L_NOTICE:
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

	void prepareLogToOutput(const std::string& text, logLevel level)
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
