#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>

#define EMPTY_SPACE " "
#define DATE_SEP "/"
#define HOUR_SEP ":"

class DateTime
{
public:
    static std::string getCurrentDate() 
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << time.tm_mday << DATE_SEP
            << std::setfill('0') << std::setw(2) << time.tm_mon + 1 << DATE_SEP
            << time.tm_year + 1900;

        return oss.str();
    }

    static std::string getCurrentTime() 
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << time.tm_hour << HOUR_SEP
            << std::setfill('0') << std::setw(2) << time.tm_min << HOUR_SEP
            << std::setfill('0') << std::setw(2) << time.tm_sec;

        return oss.str();
    }

    static std::string getCurrentDateTime() 
    {
        return getCurrentDate() + EMPTY_SPACE + getCurrentTime();
    }
};
