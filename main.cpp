#include <iostream>
#include "node.hpp"

#include <thread>
#include "message.hpp"

std::vector<march::message *> message_buffer = {};

int main(int, char **)
{

    march::node node_a = march::node();
    march::node node_b = march::node();
    // march::node node_c = march::node();
    // march::node node_d = march::node();
    // march::node node_e = march::node();
    // march::node node_f = march::node();

    int iterations = 0;

    while (true)
    {
        std::cout << "====================" << std::endl;
        std::cout << "Iteration: " << iterations++ << std::endl;
        std::cout << "====================" << std::endl;

        node_a.get_state()->update();
        node_a.execute_stack();

        std::cout << std::endl;

        node_b.get_state()->update();
        node_b.execute_stack();

        std::cout << std::endl;

        // node_c.get_state()->update();
        // node_c.execute_stack();

        // std::cout << std::endl;

        // node_d.get_state()->update();
        // node_d.execute_stack();

        // std::cout << std::endl;

        // node_e.get_state()->update();
        // node_e.execute_stack();

        // std::cout << std::endl;

        // node_f.get_state()->update();
        // node_f.execute_stack();

        // Clear message buffer

        for (auto message : message_buffer)
            delete message;

        message_buffer.clear();

        // Some empty space
        std::cout << std::endl
                  << std::endl
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
