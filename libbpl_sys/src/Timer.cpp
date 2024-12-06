//
// Created by Bradley Remedios on 12/5/24.
//
#include <bpl/sys/Timer.h>

namespace bpl::sys {
    void Timer::Reset() {
        m_nextAlarm = std::chrono::steady_clock::now() + m_timerPeriod;
    }

    bool Timer::isExpired() const {
        return std::chrono::steady_clock::now() >= m_nextAlarm;
    } // isExpired
}; // bpl::sys