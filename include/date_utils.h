#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

inline std::string get_current_iso8601() {
    auto now = std::time(nullptr);
    auto tm = *std::gmtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

#endif  // DATE_UTILS_H
