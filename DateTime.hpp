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
        std::time_t tempoAtual = std::time(nullptr);
        std::tm tempoLocal;
        localtime_s(&tempoLocal, &tempoAtual);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << tempoLocal.tm_mday << "/"
            << std::setfill('0') << std::setw(2) << tempoLocal.tm_mon + 1 << "/"
            << tempoLocal.tm_year + 1900;

        return oss.str();
    }

    std::string getCurrentTime() const
    {
        std::time_t tempoAtual = std::time(nullptr);
        std::tm tempoLocal;
        localtime_s(&tempoLocal, &tempoAtual);

        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << tempoLocal.tm_hour << ":"
            << std::setfill('0') << std::setw(2) << tempoLocal.tm_min << ":"
            << std::setfill('0') << std::setw(2) << tempoLocal.tm_sec;

        return oss.str();
    }

    std::string getCurrentDateTime() const
    {
        return getCurrentDate() + EMPTY_SPACE + getCurrentTime();
    }
};
