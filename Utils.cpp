#include "Utils.h"
#include <sstream>
#include <iomanip>
#include <chrono>

namespace Utils {

    std::string getCurrentDateMMDDYYYY() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::tm tm;  // Create a tm structure
        localtime_s(&tm, &time);  // Use localtime_s to fill the tm structure

        std::ostringstream oss;
        oss << std::put_time(&tm, "%m%d%Y");
        return oss.str();
    }

    bool isValidDateMMDDYYYY(const std::string& date) {
        if (date.length() != 8) {
            return false;
        }

        // Parse and validate month, day, and year
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(2, 2));
        int year = std::stoi(date.substr(4, 4));
        if (month < 1 || month > 12) {
            return false;
        }

        if (day < 1 || day > 31) {
            return false;
        }

        if (month == 2) { 
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                return day <= 29;
            }
            return day <= 28;
        }

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        }

        return true;
    }
}