//
// Created by Bradley Remedios on 10/25/24.
//

#ifndef BPL_SYS_PATH_H
#define BPL_SYS_PATH_H

#include <list>
#include <string>
#include <filesystem>

namespace bpl::sys {
    class Path {
    public:
        static std::string getCwd();
        static std::string getFontFilename(const std::string& filename);
        static std::string getResourceFilename(const std::string& filename, const std::string& progName="");
    private:
        static std::string getFilenameFromList_(const std::list<std::filesystem::path>& paths);
    }; // class Path
} // bpl::sys

#endif //BPL_SYS_PATH_H