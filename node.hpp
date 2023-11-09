#if !defined(MARCH_NODE_H_)
#define MARCH_NODE_H_

#include <string>
#include <iostream>
#include <vector>

#include "state.hpp"
#include "information.hpp"
#include "action.hpp"

static int node_count = 0; // Used to assign unique IDs to nodes

namespace march
{
    class node
    {
    public:
        node() : information(node_count++), state(new initialize(*this)), action_stack({}){};
        ~node() { delete state; };

    public:
        void print(std::string message)
        {
            std::cout << "[ Node " << information.get_ID() << " ( STATE: " << get_state()->get_name() << " ) ]: " << message << std::endl;
        }

    public:
        void add_action(march::action *action) { action_stack.push_back(action); };
        void execute_stack()
        {

            while (!action_stack.empty())
            {
                action_stack.back()->execute();
                delete action_stack.back();
                action_stack.pop_back();
            }
        };

        void change_state(march::state *new_state)
        {
            delete state;
            state = new_state;
        };

    public:
        auto get_information() -> march::information & { return information; };
        auto get_state() -> march::state * { return state; };

    private:
        march::information information;
        march::state *state;

    private:
        std::vector<march::action *> action_stack;
    };
}

#endif // MARCH_NODE_H_
