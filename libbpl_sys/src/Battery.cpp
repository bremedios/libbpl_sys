//
// Created by Bradley Remedios on 11/18/24.
//

#include <fstream>
#include <filesystem>
#include <iostream>

#include <bpl/sys/Battery.h>

namespace bpl::sys {

    Battery::Battery(const std::string &name) {
        m_capacityFiles.emplace_back("capacity");
        m_capacityFiles.emplace_back("capacity_level");

        m_name = name;
    }

    Battery::~Battery() = default;

    bool Battery::UpdateCapacity_() {
        for (auto &it : m_capacityFiles) {
            std::string capacityFile = m_name + "/" + it;

            //  The name of the file can be different for different types of devices.
            if (!std::filesystem::exists(capacityFile)) {
                continue;
            }

            std::ifstream file(capacityFile, std::ios_base::in);

            std::string capacity;

            std::getline(file, capacity);

            file.close();

            if (!capacity.empty() && (capacity != "Unknown")) {
                m_capacity = std::stoi(capacity);

                return true;
            }
        }

        return false;
    } // UpdateCapacity

    bool Battery::Update() {
        return UpdateCapacity_();
    } // Update

    int Battery::getCapacity() const {
        return m_capacity;
    } // getCapacity
} // bpl::sys
