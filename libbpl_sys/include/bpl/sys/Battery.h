//
// Created by Bradley Remedios on 11/18/24.
//

#ifndef BPL_SYS_BATTERY_H
#define BPL_SYS_BATTERY_H

#include <map>
#include <list>
#include <memory>
#include <string>
#include <fstream>

namespace bpl::sys {
    class Battery {
    public:
        explicit Battery(const std::string& name);
        ~Battery() = default;

        [[nodiscard]] int getCapacity() const;
        [[nodiscard]] int getChargeLevel() const;
        [[nodiscard]] int getMaxChargeLevel() const;
        [[nodiscard]] const std::string& getState() const;
        bool Update();

        bool StartLog(const std::string& logFile);
        bool StopLog();
        bool Log(const std::string& timestamp);

    private:
        Battery() = default;
        bool GetStringFromFile_(const std::string& filename, std::string& value);
        bool GetIntFromFile_(const std::string& filename, int& value);

        bool UpdateMaxChargeLevel_();
        bool UpdateChargeLevel_();
        bool UpdateCapacity_();
        bool UpdateState_();

        std::string m_logFile;

        int m_capacity=-1;
        int m_maxChargeLevel=-1;
        int m_chargeLevel=-1;
        std::string m_state="Unknown";

        std::string m_name;
        std::ofstream m_csvFile;
        std::list<std::string> m_capacityFiles;
        std::list<std::string> m_chargeLevelFiles;
        std::list<std::string> m_maxChargeLevelFiles;
        std::list<std::string> m_stateFiles;
    }; // Battery

    typedef std::shared_ptr<Battery> BatteryPtr;
    typedef std::map<std::string, BatteryPtr> BatteryMap;
} // bpl::sys

#endif // BPL_SYS_BATTERY_H