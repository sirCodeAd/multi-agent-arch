#if !defined(MARCH_ACTION_H_)
#define MARCH_ACTION_H_

#include <string>

namespace march
{

    class node;

    enum ACTION_TYPE
    {
        UPDATE_BELIEFS,
        CHARGE_BATTERY,
        CALCULATING_PRIORITY,
        BROADCAST_MESSAGE
    };

    // =========================================================
    // ACTION SUPERCLASS
    // =========================================================

    /**
     * IMPLEMENTS STRATEGY PATTERN
    */
    class action
    {
    
    //variables
    protected:
        march::node &m_node;
        ACTION_TYPE m_type;

    //constructor med parameter, vi initizierar m_node till node_
    public:
        action(march::node &node_, ACTION_TYPE type) : m_node(node_){};
        virtual ~action() = default;

    //Vi skapar en virtuel execute metod som alla subclasses kommer behöva egen funktionalitet till
    public:
        virtual void execute() = 0;

    };

    // =========================================================
    // ACTION SUBCLASSES
    // =========================================================

    class update_beliefs : public action
    {
    // Vi skapar en construction för subklassen och initizerar action superclassens parametrar med node_ och UPDATE_BELIEFS 
    public:
        update_beliefs(march::node &node_) : action(node_, ACTION_TYPE::UPDATE_BELIEFS){};

        //Denna destructor används för att frigöra resurser när instansen av denna class inte används längre
        ~update_beliefs(){};

    public:
        void execute();
    };

    class calc_priority : public action
    {

    public:
        calc_priority(march::node &node_) : action(node_, ACTION_TYPE::CALCULATING_PRIORITY){};
        ~calc_priority(){};
    
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

    class broadcast_message : public action
    {
    public:
        broadcast_message(march::node &node_, std::string message) : action(node_, ACTION_TYPE::BROADCAST_MESSAGE){};
        ~broadcast_message(){};

    public:
        void execute();

    private:
        std::string m_message;
    };

}

#endif // MARCH_ACTION_H_