#if !defined(MARCH_STATE_H_)
#define MARCH_STATE_H_

#include <string>

#include "action.hpp"

namespace march
{
    class node;

    enum STATE_TYPE
    {
        INIT,
        IDLE,
        WAITING,
        CHARGING
    };

    // =========================================================
    // STATE SUPERCLASS
    // =========================================================

    /**
     * IMPLEMENTS STATE PATTERN
     */
    class state
    {

    public:
        state(STATE_TYPE type, march::node &node_) : m_type(type), m_node(node_){};
        virtual ~state() = default;

    public:
        STATE_TYPE get_type() const { return m_type; };
        virtual std::string get_name() const = 0;
        virtual void update() = 0;

    protected:
        STATE_TYPE m_type;
        node &m_node;
    };

    // =========================================================
    // STATE SUBCLASSES
    // =========================================================

    class initialize : public state
    {
    public:
        initialize(node &node) : state(STATE_TYPE::INIT, node){};
        ~initialize(){};

    public:
        void update();
        std::string get_name() const { return "INITIALIZE"; };
    };

    // =========================================================

    class idle : public state
    {
    public:
        idle(node &node) : state(STATE_TYPE::IDLE, node) { start_idle(); };
        ~idle(){};

    public:
        void update();
        std::string get_name() const { return "IDLE"; };

    private:
        void start_idle();
    };

    // =========================================================

    class charging : public state
    {
    public:
        charging(node &node) : state(STATE_TYPE::CHARGING, node){};
        ~charging(){};

    public:
        void update();
        std::string get_name() const { return "CHARGING"; };
    };
}

#endif // MARCH_STATE_H_
