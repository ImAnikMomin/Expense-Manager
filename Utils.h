#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    std::string getCurrentDateMMDDYYYY();
    bool isValidDateMMDDYYYY(const std::string& date);
    // Other utility functions...
}

#endif // UTILS_H