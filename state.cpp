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
            m_node.print("Battery level is low, switching to calculating state");
            m_node.change_state(new calculating(m_node));
            return;
        }

        m_node.add_action(new march::update_beliefs(m_node));
    }
    //Calculating State ======================================================

    auto calculating::update() -> void
    {
            m_node.add_action(new march::update_beliefs(m_node));
            m_node.add_action(new march::calculating_priority(m_node));
            // return;
        
        
        
    }

    // Charging State =========================================================

    auto charging::update() -> void
    {
        if (m_node.get_information().get_battery_level() >= m_node.get_information().get_destination())
        {
            m_node.print("Battery level is high enough, switching to idle state");
            m_node.add_action(new march::broadcast_message(m_node, MESSAGE_TYPE::BROADCAST, "DONE CHARGING"));
            m_node.change_state(new idle(m_node));

            return;
        }
        
        m_node.add_action(new march::update_beliefs(m_node));
        m_node.add_action(new march::charge_battery(m_node));
    }

    auto moving::update() -> void
    {
        if (m_node.get_information().get_position() == m_new_position)
        {
            m_node.print("Arrived at destination, switching to idle state");
            m_node.change_state(new idle(m_node));
            return;
        }

        m_node.add_action(new march::move_to(m_node, m_new_position));
        m_node.add_action(new march::update_beliefs(m_node));
    }
}
