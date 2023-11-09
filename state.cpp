#include "state.hpp"

#include <iostream>
#include "node.hpp"
#include "action.hpp"

namespace march
{

    // Initialize State =========================================================

    auto initialize::update() -> void
    {
        m_node.print("Initializing, switching to idle state");
        m_node.change_state(new idle(m_node));
    }

    // Idle State =========================================================

    auto idle::update() -> void
    {

        if (m_node.get_information().get_battery_level() < m_node.get_information().get_destination())
        {
            m_node.print("Battery level is low, switching to charging state");
            m_node.change_state(new charging(m_node));
            return;
        }

        m_node.add_action(new march::update_beliefs(m_node));
    }

    // Charging State =========================================================

    auto charging::update() -> void
    {
        if (m_node.get_information().get_battery_level() >= m_node.get_information().get_destination())
        {
            m_node.print("Battery level is high enough, switching to idle state");
            m_node.change_state(new idle(m_node));
            return;
        }

        m_node.add_action(new march::update_beliefs(m_node));
        m_node.add_action(new march::charge_battery(m_node));
    }

}
