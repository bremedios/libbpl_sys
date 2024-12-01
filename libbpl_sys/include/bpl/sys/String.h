//
// Created by Bradley Remedios on 11/21/24.
//
#ifndef BPL_SYS_STRING_H
#define BPL_SYS_STRING_H

#include <string>
#include <algorithm>

namespace bpl::sys::string {
    std::string inline tolower(std::string s)
    {
        std::ranges::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); }
                      );
        return s;
    } // tolower
}; // bpl::sys
#endif //BPL_SYS_STRING_H