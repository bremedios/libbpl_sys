//
// Created by Bradley Remedios on 11/18/24.
//

#ifndef SYSAPI_BATTERIES_H
#define SYSAPI_BATTERIES_H

#include <map>

#include "Battery.h"

namespace sysapi {

    class Batteries {
    public:
        Batteries();
        ~Batteries();

        bool Load();

        [[nodiscard]] BatteryPtr getBattery(const std::string& name);
        [[nodiscard]] const BatteryMap& getBatteryMap() const;

        void Update();
    private:
        BatteryMap m_batteries;
    };

} // sysapi

#endif //SYSAPI_BATTERIES_H
