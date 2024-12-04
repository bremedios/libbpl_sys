//
// Created by Bradley Remeddos on 12/4/24.
//

#ifndef BPL_SYS_HARDWARE_H
#define BPL_SYS_HARDWARE_H

#include <string>

namespace bpl::sys {
    class Hardware {
    public:
        Hardware();
        ~Hardware()=default;

        int getDisplayWidth(void) {return m_displayWidth;}
        int getDisplayHeight(void) {return m_displayHeight;}
        bool getFullscreen(void) {return m_fullscreen;}
        const std::string& getBoardName(void) {return m_boardName;}
    private:
        void loadBoardName_();

        int          m_displayWidth    = 720;
        int          m_displayHeight   = 720;
        bool         m_fullscreen      = false;
        std::string  m_boardName;
    }; // class Hardware
} // bpl::sys

#endif //BPL_SYS_HARDWARE_H