#include <iostream>
#include "node.hpp"

#include <thread>

int main(int, char **)
{

    march::node node_a = march::node();
    march::node node_b = march::node();

    node_a.get_state()->update();
    node_a.execute_stack();

    node_b.get_state()->update();
    node_b.execute_stack();

    int iterations = 0;

    while (true)
    {
        std::cout << "====================" << std::endl;
        std::cout << "Iteration: " << iterations++ << std::endl;
        std::cout << "====================" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        node_a.get_state()->update();
        node_a.execute_stack();

        std::cout << std::endl;

        node_b.get_state()->update();
        node_b.execute_stack();
    }

    return 0;
}
