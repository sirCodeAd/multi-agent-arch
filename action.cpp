#include "action.hpp"

#include "node.hpp"

namespace march
{
    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    void update_beliefs::execute()
    {
        m_node.print("Updating information");

        // TODO: Update beliefs should be tasks that update certain beliefs,
        //       but right now it does nothing.

        return;
    }

    void charge_battery::execute()

    {
        // TEMPORARY

        int new_battery_level = m_node.get_information().get_battery_level() + 10;
        m_node.get_information().update_battery_level(new_battery_level);

        m_node.print("Battery level: " + std::to_string(m_node.get_information().get_battery_level()));
    }

}
