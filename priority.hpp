#if !defined(MARCH_PRIORITY_H_)
#define MARCH_PRIORITY_H_

#include <iostream>
#include <algorithm>

#include "information.hpp"

namespace march
{
    class node;

    class priority
    {

    protected:
    march::node &m_node;

    public:
        priority(march::node &node_) : m_node(node_){};
        virtual ~priority() = default;

    public:
        
        double priority_score();

    };


}

#endif // MARCH_PRIORITY_H_