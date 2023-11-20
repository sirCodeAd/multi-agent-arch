#if !defined(MARCH_INFORMATION_H_)
#define MARCH_INFORMATION_H_

#include <cstdlib>

namespace march
{
    class information
    {
    public:
        information(int ID_) : ID(ID_), battery_level(rand() % 100), cargo_weight(rand() % 100), destination(rand() % 100), position(rand() % 100){};
        ~information(){};

    public:
        int get_ID() { return ID; };
        int get_battery_level() { return battery_level; };
        int get_cargo_weight() { return cargo_weight; };
        int get_destination() { return destination; };
        int get_position() { return position; };

    public:
        // These functions are used to update the information of the node,
        // which will be the beliefs upon which the node will act and make decisions.

        int update_battery_level(int amount) { return battery_level = amount; };
        int update_cargo (int weight) {return cargo_weight = weight; };
        int update_destination(int new_destination) { return destination = new_destination; };
        int update_position(int new_position) { return position = new_position; };

    private:
        int ID;
        int battery_level;
        int cargo_weight;

    private:
        int destination;
        int position;
    };
}

#endif // MARCH_INFORMATION_H_
