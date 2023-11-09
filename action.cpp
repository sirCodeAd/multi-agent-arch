#include "action.hpp"

#include "node.hpp"

namespace march
{
    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    void update_beliefs::execute()
    {
        m_node.print("Updating beliefs");

        m_node.get_information().update_battery_level();
        m_node.get_information().update_destination();
        m_node.get_information().update_position();
    }
}
