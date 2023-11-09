#if !defined(MARCH_STATE_H_)
#define MARCH_STATE_H_

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

    class state
    {

    public:
        state(STATE_TYPE type, march::node &node_) : m_type(type), m_node(node_){};
        virtual ~state() = default;

    public:
        STATE_TYPE get_type() const { return m_type; };
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
    };

    // =========================================================

    class idle : public state
    {
    public:
        idle(node &node) : state(STATE_TYPE::IDLE, node){};
        ~idle(){};

    public:
        void update();
    };

}

#endif // MARCH_STATE_H_
