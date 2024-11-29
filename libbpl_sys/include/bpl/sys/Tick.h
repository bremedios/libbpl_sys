//
// Created by Bradley Remedios on 11/27/24.
//

#ifndef BPL_SYS_TICK_H
#define BPL_SYS_TICK_H

#include <chrono>

namespace bpl::sys {

    class Tick {
    public:
        explicit Tick(std::chrono::milliseconds period);
        ~Tick() = default;

        void Wait(std::chrono::milliseconds maxWait);
        void Wait(unsigned int maxWait);
        void Wait();

        void Reset();

        void setPeriod(unsigned int period) { m_period = std::chrono::milliseconds(period); }
        void setPeriod(std::chrono::milliseconds period) { m_period = period; }
    private:
        std::chrono::time_point<std::chrono::steady_clock> m_tick;
        std::chrono::milliseconds                          m_period = std::chrono::milliseconds(1000);
    }; // class Tick
}; // namespace bpl::sys
#endif //BPL_SYS_TICK_H