//
// Created by Bradley Remedios on 11/18/24.
//

#ifndef BPL_SYS_BATTERY_H
#define BPL_SYS_BATTERY_H

#include <map>
#include <list>
#include <memory>
#include <string>

namespace bpl::sys {
    class Battery {
    public:
        explicit Battery(const std::string& name);
        ~Battery();

        [[nodiscard]] int getCapacity() const;

        bool Update();
    private:
        Battery() = default;

        bool UpdateCapacity_();

        int m_capacity=0;
        std::string m_name;
        std::list<std::string> m_capacityFiles;
    }; // Battery

    typedef std::shared_ptr<Battery> BatteryPtr;
    typedef std::map<std::string, BatteryPtr> BatteryMap;
} // bpl::sys

#endif // BPL_SYS_BATTERY_H
