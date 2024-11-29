//
// Created by Bradley Remedios on 11/15/24.
//

#include <bpl/sys/Stopwatch.h>

namespace bpl::sys {
    void Stopwatch::Start() {
        m_start = std::chrono::steady_clock::now();
    } // Start

    void Stopwatch::Stop() {
        m_stop = std::chrono::steady_clock::now();
    } // Stop

    unsigned int Stopwatch::getMilliseconds() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start).count();
    } // getMilliseconds
} // bpl::sys