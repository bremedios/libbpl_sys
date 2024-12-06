//
// Created by Bradley Remedios on 12/5/24.
//

#ifndef BPL_SYS_TIMER_H
#define BPL_SYS_TIMER_H

#include <chrono>

namespace bpl::sys {
    class Timer {
    public:
        Timer(std::chrono::microseconds microseconds)
            : m_timerPeriod(microseconds){}

        ~Timer() = default;

        void Reset();
        bool isExpired() const;
    private:
        Timer() = delete;
        std::chrono::time_point<std::chrono::steady_clock>   m_nextAlarm;
        std::chrono::microseconds               m_timerPeriod;
    }; // Timer
}; // namespace bpl::sys
#endif //BPL_SYS_TIMER_H