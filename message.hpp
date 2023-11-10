#if !defined(MARCH_MESSAGE_H_)
#define MARCH_MESSAGE_H_

#include <string>

#include "information.hpp"

namespace march
{
    enum MESSAGE_TYPE
    {
        HELLO,
        GOODBYE,
        REQUEST,
        RESPONSE,
        ERROR
    };

    class message
    {
    public:
        message(MESSAGE_TYPE type, std::string body) : m_type(type), m_body(body){};
        ~message();

    public:
        MESSAGE_TYPE m_type;
        std::string m_body;
    };

    class global_message : public message
    {
    public:
        global_message(std::string body, march::information sender_information) : message(MESSAGE_TYPE::HELLO, body), m_sender_information(sender_information){};

    public:
        march::information m_sender_information;
    };
}

#endif