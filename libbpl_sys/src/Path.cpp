//
// Created by Bradley Remedios on 10/25/24.
//

#include <cstring>
#include <iostream>
#include <ostream>
#include <list>
#include <filesystem>

#include <bits/fs_fwd.h>
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
    } // getCwd

    std::string Path::getResourceFilename(std::string file) {
        std::list<std::filesystem::path> paths;

        paths.emplace_back(file);
        paths.emplace_back("/usr/local/share/"+file);
        paths.emplace_back("/usr/local/share/games/"+file);

        //  Check if its in our current working directory
        //if (std::filesystem::exists(std::filesystem::exists({file}))) {
        //    return file;
        //}

        for (auto& it : paths) {
            if (std::filesystem::exists(it)) {
                return it.string();
            }
        }

        return "";
    } // getResourceFilename
} // bpl::sys