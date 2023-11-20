#include "priority.hpp"
#include "node.hpp"

namespace march 
{
    double priority::priority_score() {
        // Implementation using march::node
        return (1.6 * m_node.get_information().get_destination()) - 
               (100 / (m_node.get_information().get_battery_level() + 1)) -
               (0.2 * m_node.get_information().get_cargo_weight());
    }
}