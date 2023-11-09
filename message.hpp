#if !defined(MARCH_MESSAGE_H_)
#define MARCH_MESSAGE_H_

namespace march
{
    enum MESSAGE_TYPE
    {
        // Message types used by nodes (multi agent systems) to communicate
        // with each other.
        HELLO,
        GOODBYE,
        REQUEST,
        RESPONSE,
        ERROR
    };

    class message
    {
    };

}

#endif