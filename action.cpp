#include "action.hpp"

#include "node.hpp"
#include "message.hpp"

extern std::vector<march::message *> message_buffer;

namespace march
{
    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    void update_beliefs::execute()
    {
        m_node.print("Updating beliefs");

        // TODO: Update beliefs should be tasks that update certain beliefs,
        //       but right now it does nothing.

        for (auto &message : message_buffer)
        {
            if (message->m_type == MESSAGE_TYPE::HELLO)
            {
                m_node.print("Received message: " + message->m_body);
            }
        }

        return;
    }

    void charge_battery::execute()
    {
        // TEMPORARY

        int new_battery_level = m_node.get_information().get_battery_level() + 10;
        m_node.get_information().update_battery_level(new_battery_level);

        m_node.print("Battery level: " + std::to_string(m_node.get_information().get_battery_level()));
    }

    void broadcast_message::execute()
    {
        m_node.print("Broadcasting message");

        message *new_message = new global_message("HELLO", m_node.get_information());
        message_buffer.push_back(new_message);
    }

}
