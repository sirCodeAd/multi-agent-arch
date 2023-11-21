#include <iomanip>
#include <iostream>
#include <sstream>

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

        // Eg. battery level, location, etc.

        for (auto &message : message_buffer)
        {
            switch (message->m_type)
            {
            case MESSAGE_TYPE::BROADCAST:
            {
                auto broadcasted_message = dynamic_cast<march::global_message *>(message);

                if (broadcasted_message->m_body == "DONE CHARGING")
                {
                    m_node.change_state(new march::moving(m_node, broadcasted_message->m_sender_information.get_position()));
                    return;
                }

                else if (broadcasted_message->m_body == "I NEED TO CHARGE")
                {
                    m_node.change_state(new march::calculating(m_node));
                    return;
                }

                else if (broadcasted_message->m_body == "PRIORITY SCORE CALCULATED")
                {
                    m_node.change_state(new march::charging(m_node));
                    return;
                }

                break;
            }

            default:
                break;

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

    void calculating_priority::execute()
    {

        double score = m_node.get_priority_score();

        //used to limit number of decimals in score.
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << score;
        std::string score_stream = stream.str();
        
        //m_node.print("Priority score: " + std::to_string(m_node.get_priority_score()));
        m_node.print("Priority score: " + score_stream);
        
    }

    void broadcast_message::execute()
    {
        m_node.print("Broadcasting message");

        march::global_message *new_message = new march::global_message(m_message, m_message_type, m_node.get_information());

        // TEMPORARY
        // Will be replaced by sending the message to the server which will then
        // broadcast it to all nodes

        message_buffer.push_back(new_message);
    }

    void move_to::execute()
    {
        m_node.print("Moving closer to " + std::to_string(m_new_position) + " (current position: " + std::to_string(m_node.get_information().get_position()) + ")");

        int direction = 1;

        if (m_new_position < m_node.get_information().get_position())
            direction = -1;

        m_node.get_information().update_position(m_node.get_information().get_position() + direction);
    }

}
