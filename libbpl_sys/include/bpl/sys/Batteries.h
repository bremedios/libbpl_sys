//
// Created by Bradley Remedios on 11/18/24.
//

#ifndef BPL_SYS_BATTERIES_H
#define BPL_SYS_BATTERIES_H

#include <map>

#include <bpl/sys/Battery.h>

namespace bpl::sys {

    class Batteries {
    public:
        Batteries();
        ~Batteries();

        bool Load();

        [[nodiscard]] BatteryPtr getBattery(const std::string& name);
        [[nodiscard]] const BatteryMap& getBatteryMap() const;

        void Update();

        bool StartLog(const std::string &logFile);
        bool StopLog();
        bool Log(const std::string& timestamp);

    private:
        BatteryMap m_batteries;
    };

} // bpl::sys

#endif // BPL_SYS_BATTERIES_H