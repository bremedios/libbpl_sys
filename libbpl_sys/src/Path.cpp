//
// Created by Bradley Remedios on 10/25/24.
//

#include <cstring>
#include <iostream>
#include <ostream>

#include <unistd.h>

#include <bpl/sys/Path.h>

namespace bpl::sys {
    std::string Path::getCwd() {
        //
        //  This will allocate the path via malloc.
        //
        char* cwd =  getcwd(nullptr, 0);

        if (nullptr == cwd) {
            std::cerr << "getcwd failed: " << strerror(errno) << std::endl;

            return {};
        }

        std::string current_directory (cwd);

        free(cwd);

        return current_directory;
    } // GetCwd
} // bpl::sys