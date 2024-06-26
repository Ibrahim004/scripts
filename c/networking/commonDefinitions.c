#include <netinet/in.h>
#include "commonDefinitions.h"

struct sockaddr_in getServerAddress()
{
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    return address;
}