//
// Created by Bradley Remedios on 11/18/24.
//
#include <fstream>
#include <filesystem>
#include <iostream>

#include <bpl/sys/Battery.h>

#include "Debug.h"

namespace bpl::sys {
    Battery::Battery(const std::string &name) {
        m_capacityFiles.emplace_back("capacity");
        m_capacityFiles.emplace_back("capacity_level");
        m_chargeLevelFiles.emplace_back("charge_counter");
        m_maxChargeLevelFiles.emplace_back("charge_full");
        m_stateFiles.emplace_back("status");

        m_name = name;
    }

    bool Battery::GetIntFromFile_(const std::string& filename, int& value) {
        if (!std::filesystem::exists(filename)) {

            return false;
        }

        std::ifstream file(filename, std::ios_base::in);

        std::string str;

        std::getline(file, str);

        file.close();

        if (!str.empty() && (str != "Unknown")) {
            value = std::stoi(str);

            return true;
        }

        return false;
    } // GetIntFromFile_

    bool Battery::GetStringFromFile_(const std::string& filename, std::string& value) {
        if (!std::filesystem::exists(filename)) {
            return false;
        }

        std::ifstream file(filename, std::ios_base::in);

        std::getline(file, value);

        return !value.empty();
    } // GetIntFromFile_

    bool Battery::UpdateCapacity_() {
        for (auto &it : m_capacityFiles) {
            std::string capacityFile = m_name + "/" + it;

            if  (GetIntFromFile_(capacityFile, m_capacity)) {
                return true;
            }
        }

        return false;
    } // UpdateCapacity

    bool Battery::UpdateChargeLevel_() {
        for (auto &it : m_chargeLevelFiles) {
            std::string chargeLevelFile = m_name + "/" + it;

            if  (GetIntFromFile_(chargeLevelFile, m_chargeLevel)) {
                return true;
            }
        }

        return false;
    } // UpdateChargeLevel_

    bool Battery::UpdateMaxChargeLevel_() {
        for (auto &it : m_maxChargeLevelFiles) {
            std::string maxChargeLevelFile = m_name + "/" + it;

            if  (GetIntFromFile_(maxChargeLevelFile, m_maxChargeLevel)) {
                return true;
            }
        }

        return false;
    } // UpdateMaxChargeLevel_

    bool Battery::UpdateState_() {
        for (auto &it : m_stateFiles) {
            std::string stateFile = m_name + "/" + it;

            if  (GetStringFromFile_(stateFile, m_state)) {
                return true;
            }
        }

        return false;
    } // UpdateState_

    bool Battery::Update() {
        return UpdateCapacity_() && UpdateChargeLevel_() && UpdateMaxChargeLevel_() && UpdateState_();
    } // Update

    int Battery::getCapacity() const {
        return m_capacity;
    } // getCapacity

    int Battery::getChargeLevel() const {
        return m_chargeLevel;
    } // getChargeLevel

    int Battery::getMaxChargeLevel() const {
        return m_maxChargeLevel;
    } // getMaxChargeLevel

    const std::string& Battery::getState() const {
        return m_state;
    } // getState

    bool Battery::StartLog(const std::string &logFile) {
        std::string logname = m_name;

        std::erase(logname, '/');

        m_logFile = logFile + "_" + logname + ".csv";

        m_csvFile = std::ofstream(m_logFile);

        if (!m_csvFile.is_open()) {
            ERROR_MSG("    ERROR: Could not open file " << m_logFile);

            return false;
        }

        m_csvFile << "Timestamp, Capacity, Charge Value, Max Charge Value, State" << std::endl << std::flush;

        return true;
    } // StartLog

    bool Battery::Log(const std::string& timestamp) {
        m_csvFile << timestamp << "," << m_capacity << ",";
        m_csvFile << m_chargeLevel << "," << m_maxChargeLevel << ",";
        m_csvFile << m_state << std::endl << std::flush;

        return true;
    } // Log

    bool Battery::StopLog() {
        m_csvFile.close();

        return true;
    } // StopLog

} // bpl::sys