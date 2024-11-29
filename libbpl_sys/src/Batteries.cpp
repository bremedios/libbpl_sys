//
// Created by Bradley Remedios on 11/18/24.
//

#include <filesystem>
#include <ranges>

#include <bpl/sys/Batteries.h>

namespace bpl::sys {
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

    bool Batteries::StartLog(const std::string &logFile) {
        bool result = true;

        for (auto & battery : std::views::values(m_batteries)) {
            result &= battery->StartLog(logFile);
        }

        return result;
    } // StartLog

    bool Batteries::StopLog() {
        bool result = true;

        for (auto & battery : std::views::values(m_batteries)) {
            result &= battery->StopLog();
        }

        return result;
    } // StopLog

    bool Batteries::Log(const std::string& timestamp) {
        bool result = true;

        for (auto & battery : std::views::values(m_batteries)) {
            result &= battery->Log(timestamp);
        }

        return result;
    } // Log
} // bpl::sys