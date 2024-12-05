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

#include "Debug.h"

namespace bpl::sys {
    std::string Path::getCwd() {
        //
        //  This will allocate the path via malloc.
        //
        char* cwd =  getcwd(nullptr, 0);

        if (nullptr == cwd) {
            ERROR_MSG("getcwd failed: " << strerror(errno));

            return {};
        }

        std::string current_directory (cwd);

        free(cwd);

        return current_directory;
    } // getCwd

    std::string Path::getFilenameFromList_(const std::list<std::filesystem::path>& paths) {
        for (auto& it : paths) {
            if (std::filesystem::exists(it)) {

                return it.string();
            }
            else {
                DEBUG_MSG("File does not exist: " << it.string());
            }
        }

        return {""};
    } // getFilenameFromList_

    std::string Path::getFontFilename(const std::string& filename) {
        std::list<std::filesystem::path> paths;

        if (filename.empty()) {
            return filename;
        }

        // If its an absolute path we will not alter it.
        if (filename[0] == '/') {
            return filename;
        }

        paths.emplace_back(filename);
        paths.emplace_back("resources/fonts/"+filename);
        paths.emplace_back("/usr/share/fonts/"+filename);
        paths.emplace_back("/usr/local/share/fonts/"+filename);

        return getFilenameFromList_(paths);
    } // getFontFilename

    std::string Path::getResourceFilename(const std::string& filename, const std::string& progName) {
        std::list<std::filesystem::path> paths;

        std::string progPathName = "";

        if (!progName.empty()) {
            progPathName = progName + "/";
        }

        paths.emplace_back(filename);
        paths.emplace_back("resources/"+filename);
        paths.emplace_back("/usr/share/"+progPathName+filename);
        paths.emplace_back("/usr/share/games/"+progPathName+filename);
        paths.emplace_back("/usr/local/share/"+progPathName+filename);
        paths.emplace_back("/usr/local/share/games/"+progPathName+filename);

        return getFilenameFromList_(paths);
    } // getResourceFilename
} // bpl::sys