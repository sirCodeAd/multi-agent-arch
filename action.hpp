#if !defined(MARCH_ACTION_H_)
#define MARCH_ACTION_H_

namespace march
{

    class node;

    // =========================================================
    // ACTION SUPERCLASS
    // =========================================================

    class action
    {
    public:
        action(march::node &node_) : m_node(node_){};
        virtual ~action() = default;

    public:
        virtual void execute() = 0;

    protected:
        march::node &m_node;
    };

    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    class update_beliefs : public action
    {
    public:
        update_beliefs(march::node &node_) : action(node_){};
        ~update_beliefs(){};

    public:
        void execute();
    };

}

#endif // MARCH_ACTION_H_