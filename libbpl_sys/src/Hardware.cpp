//
// Created by Bradley Remedios on 12/4/24.
//
#include <fstream>
#include <string>
#include <filesystem>

#include <bpl/sys/Hardware.h>

#include "Debug.h"

namespace bpl::sys {
    Hardware::Hardware() {
        loadBoardName_();

        if (m_boardName == "rg-cubexx") {
            m_displayWidth   = 720;
            m_displayHeight  = 720;
            m_fullscreen     = true;
        }
        else if (m_boardName == "rg40xx-v") {
            m_displayWidth   = 640;
            m_displayHeight  = 480;
            m_fullscreen     = true;
        }
    } // Hardware

    void Hardware::loadBoardName_() {
        // if this is a batocera-based system the board will be defined in the
        // boot partition
        if (std::filesystem::exists("/boot/boot/batocera.board")) {
            std::ifstream ifs("/boot/boot/batocera.board");

            if (!ifs.is_open()) {
                ERROR_MSG("/boot/boot/batocera.board exists but cannot be opened");
                return;
            }

            std::string boardName;

            if (!std::getline(ifs, m_boardName))
            {
                ERROR_MSG("Failed to read board name from /boot/boot/batocera.board");

                return;
            }
        }
    } // loadBoardName_
}; // bpl::sys