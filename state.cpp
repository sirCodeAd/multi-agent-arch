#include "state.hpp"

#include <iostream>
#include "node.hpp"
#include "action.hpp"

namespace march
{
    auto initialize::update() -> void
    {
        m_node.print("Initializing");

        march::action *action_1 = new march::update_beliefs(m_node);
        m_node.add_action(action_1);
        m_node.execute_stack();

        if (m_node.get_information().get_battery_level() > 50)
        {
            m_node.change_state(new idle(m_node));
        }

        m_node.print("Battery level too low to idle");
    }

    auto idle::update() -> void
    {
        m_node.print("Idling");
    }

}
