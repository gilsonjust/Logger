#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>

#define EMPTY_SPACE " "

class DateTime
{
public:
    std::string getCurrentDate() const
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << time.tm_mday << "/"
            << std::setfill('0') << std::setw(2) << time.tm_mon + 1 << "/"
            << time.tm_year + 1900;

        return oss.str();
    }

    std::string getCurrentTime() const
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &currentTime);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << time.tm_hour << ":"
            << std::setfill('0') << std::setw(2) << time.tm_min << ":"
            << std::setfill('0') << std::setw(2) << time.tm_sec;

        return oss.str();
    }

    std::string getCurrentDateTime() const
    {
        return getCurrentDate() + EMPTY_SPACE + getCurrentTime();
    }
};
