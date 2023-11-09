#if !defined(MARCH_INFORMATION_H_)
#define MARCH_INFORMATION_H_

#include <cstdlib>

namespace march
{
    class information
    {
    public:
        information(int ID_) : ID(ID_){};
        ~information(){};

    public:
        int get_ID() { return ID; };
        int get_battery_level() { return battery_level; };
        int get_destination() { return destination; };
        int get_position() { return position; };

    public:
        // These functions are used to update the information of the node,
        // which will be the beliefs upon which the node will act and make decisions.

        int update_battery_level() { return battery_level = rand() % 100; };
        int update_destination() { return destination = rand() % 100; };
        int update_position() { return position = rand() % 100; };

    private:
        int ID;
        int battery_level;

    private:
        int destination;
        int position;
    };
}

#endif // MARCH_INFORMATION_H_
