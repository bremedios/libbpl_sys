//
// Created by Bradley Remedios on 12/13/24.
//
#include <string.h>
#include <chrono>
#include <bpl/sys/LocalTimePoint.h>

namespace bpl::sys {
    void LocalTimePoint::setNow() {
        memset(&m_timePoint, 0, sizeof(m_timePoint));

        std::time_t  t  = std::time(0);
        std::tm*     tm = std::localtime(&t);

        m_timePoint.tm_hour = tm->tm_hour;
        m_timePoint.tm_min  = tm->tm_min;
        m_timePoint.tm_sec  = tm->tm_sec;
    } // setNow

    void LocalTimePoint::set(int hour, int minute, int second) {
        m_timePoint.tm_hour = hour;
        m_timePoint.tm_min  = minute;
        m_timePoint.tm_sec  = second;
    } // set

    bool LocalTimePoint::operator==(const LocalTimePoint& rhs) const {
        if (m_timePoint.tm_hour != rhs.m_timePoint.tm_hour) {
            return false;
        }
        if (m_timePoint.tm_min != rhs.m_timePoint.tm_min) {
            return false;
        }
        if (m_timePoint.tm_sec != rhs.m_timePoint.tm_sec) {
            return false;
        }

        return true;
    } // operator==

    bool LocalTimePoint::operator<(const LocalTimePoint& rhs) const {
        if (m_timePoint.tm_hour > rhs.m_timePoint.tm_hour) {
            return false;
        }
        else if (m_timePoint.tm_hour < rhs.m_timePoint.tm_hour) {
            return true;
        }
        else {
            if (m_timePoint.tm_min > rhs.m_timePoint.tm_min) {
                return false;
            }
            else if (m_timePoint.tm_min < rhs.m_timePoint.tm_min) {
                return true;
            } else {
                if (m_timePoint.tm_sec > rhs.m_timePoint.tm_sec) {
                    return false;
                }
                else if (m_timePoint.tm_sec < rhs.m_timePoint.tm_sec) {
                    return true;
                }
                else
                {
                  return false;
                }
            }
        }
    } // operator<

    bool LocalTimePoint::operator>(const LocalTimePoint& rhs) const {
        if (operator==(rhs)) {
            return false;
        } else if (operator<(rhs)) {
            return false;
        }
        else {
            return true;
        }
    } // operator>

}; // bpl::sys