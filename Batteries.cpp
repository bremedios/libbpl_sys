//
// Created by Bradley Remedios on 11/18/24.
//

#include <filesystem>
#include <ranges>

#include "Batteries.h"

namespace sysapi {
    Batteries::Batteries() = default;

    Batteries::~Batteries() {
        m_batteries.clear();
    }

    bool Batteries::Load() {
        std::string systemPath = "/sys/class/power_supply/";

        for (const auto& dir : std::filesystem::directory_iterator(systemPath)) {
            if (dir.is_directory()) {
                BatteryPtr battery = std::make_shared<Battery>(dir.path());

                m_batteries.insert(std::pair<std::string, BatteryPtr>(dir.path(), battery));
            }
        }

        return true;
    } // Load

    BatteryPtr Batteries::getBattery(const std::string &name) {
        return m_batteries[name];
    } // getBattery

    const BatteryMap& Batteries::getBatteryMap() const {
        return m_batteries;
    } // getBatteryMap

    void Batteries::Update() {
        for (auto & battery : std::views::values(m_batteries)) {
            battery->Update();
        }

    } // Update
} // sysapi
