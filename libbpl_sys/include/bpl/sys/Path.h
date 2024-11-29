//
// Created by Bradley Remedios on 10/25/24.
//

#ifndef BPL_SYS_PATH_H
#define BPL_SYS_PATH_H

#include <string>

namespace bpl::sys {
    class Path {
    public:
        static std::string getCwd();
    }; // class Path
} // bpl::sys

#endif //BPL_SYS_PATH_H