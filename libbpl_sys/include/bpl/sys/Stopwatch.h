//
// Created by Bradley Remedios on 11/15/24.
//

#ifndef BPL_SYS_STOPWATCH_H
#define BPL_SYS_STOPWATCH_H

#include <chrono>

namespace bpl::sys {
    class Stopwatch {
    public:
        Stopwatch()=default;
        ~Stopwatch()=default;

        void Start();
        void Stop();

        [[nodiscard]] unsigned int getMilliseconds() const;

    private:
        std::chrono::time_point<std::chrono::steady_clock>    m_start;
        std::chrono::time_point<std::chrono::steady_clock>    m_stop;
    };

} // bpl::sys

#endif //BPL_SYS_STOPWATCH_H