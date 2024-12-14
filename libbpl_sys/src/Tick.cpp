//
// Created by Bradley Remedios on 11/27/24.
//
#include <thread>
#include <chrono>

#include "bpl/sys/Tick.h"

namespace bpl::sys {
    Tick::Tick(std::chrono::milliseconds period) {
        m_period = period;
        Reset();
    }

    void Tick::Reset() {
        m_tick = std::chrono::steady_clock::now() + m_period;
    } // Reset

    void Tick::Release() {
        m_cv.notify_all();
    }

    void Tick::Wait() {
        std::unique_lock<std::mutex> lock(m_mutex);

        m_cv.wait_until(lock, m_tick);

        m_tick += m_period;
    } // Wait

    void Tick::Wait(std::chrono::milliseconds maxWait) {
        std::unique_lock<std::mutex> lock(m_mutex);

        auto max = std::chrono::steady_clock::now() + maxWait;

        m_cv.wait_until(lock, std::min(m_tick, max));

        if (std::chrono::steady_clock::now() > m_tick) {
            m_tick += m_period;
        }
    } // Wait

    void Tick::Wait(unsigned int maxWait) {
        Wait(std::chrono::milliseconds(maxWait));
    } // Wait
}; // namespace bpl::sys