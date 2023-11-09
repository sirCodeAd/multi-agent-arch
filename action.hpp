#if !defined(MARCH_ACTION_H_)
#define MARCH_ACTION_H_

namespace march
{

    class node;

    enum ACTION_TYPE
    {
        UPDATE_BELIEFS,
        CHARGE_BATTERY
    };

    // =========================================================
    // ACTION SUPERCLASS
    // =========================================================

    class action
    {
    public:
        action(march::node &node_, ACTION_TYPE type) : m_node(node_){};
        virtual ~action() = default;

    public:
        virtual void execute() = 0;

    protected:
        march::node &m_node;
        ACTION_TYPE m_type;
    };

    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    class update_beliefs : public action
    {
    public:
        update_beliefs(march::node &node_) : action(node_, ACTION_TYPE::UPDATE_BELIEFS){};
        ~update_beliefs(){};

    public:
        void execute();
    };

    class charge_battery : public action
    {
    public:
        charge_battery(march::node &node_) : action(node_, ACTION_TYPE::CHARGE_BATTERY){};
        ~charge_battery(){};

    public:
        void execute();
    };

}

#endif // MARCH_ACTION_H_