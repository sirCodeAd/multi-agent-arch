#include <iostream>
#include "node.hpp"

#include <thread>
#include "message.hpp"

std::vector<march::message *> message_buffer = {};

int main(int, char **)
{

    march::node node_a = march::node();
    march::node node_b = march::node();

    int iterations = 0;

    while (true)
    {

        // Some empty space
        // std::cout << std::endl
        //           << std::endl
        //           << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "====================" << std::endl;
        std::cout << "Iteration: " << iterations++ << std::endl;
        std::cout << "====================" << std::endl;

        node_a.get_state()->update();
        node_a.execute_stack();

        std::cout << std::endl;

        node_b.get_state()->update();
        node_b.execute_stack();

        // Clear message buffer

        message_buffer.clear();

        // Some empty space
        std::cout << std::endl
                  << std::endl
                  << std::endl;
    }

    return 0;
}
