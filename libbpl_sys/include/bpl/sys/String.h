//
// Created by Bradley Remedios on 11/21/24.
//
#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include <string>
#include <algorithm>

namespace utils {
    namespace string {
        std::string inline tolower(std::string s)
        {
            std::ranges::transform(s.begin(), s.end(), s.begin(),
                           [](unsigned char c){ return std::tolower(c); }
                          );
            return s;
        }
    };
}
#endif //UTILS_STRING_H