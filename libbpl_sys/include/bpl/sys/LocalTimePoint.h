//
// Created by Bradley Remedios on 12/13/24.
//

#ifndef BPL_SYS_LOCALTIMEPOINT_H
#define BPL_SYS_LOCALTIMEPOINT_H

#include <chrono>

namespace bpl::sys {
    class LocalTimePoint {
    public:
        void setNow();
        void set(int hour, int minute, int second);

        bool operator<(const LocalTimePoint& rhs) const;
        bool operator>(const LocalTimePoint& rhs) const;
        bool operator==(const LocalTimePoint& rhs) const;

        int getHour() const { return m_timePoint.tm_hour; }
        int getMinute() const { return m_timePoint.tm_min; }
        int getSecond() const { return m_timePoint.tm_sec; }
    private:
        std::tm              m_timePoint;
    }; // LocalTimePoint
}; // bpl::sys
#endif //BPL_SYS_LOCALTIMEPOINT_H