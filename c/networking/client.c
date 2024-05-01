#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include "commonDefinitions.h"

int createClientSocket()
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_fd < 0)
    {
        perror("Could not open client socket");
        exit(EXIT_FAILURE);
    }
    return client_fd;
}

void connectClientToServer(int client_fd, struct sockaddr* address)
{
    int status = connect(client_fd, address, sizeof(*address));
    if(status < 0)
    {
        perror("Could not connect!");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    struct sockaddr_in server_address = getServerAddress();
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    int client_fd = createClientSocket();
    connectClientToServer(client_fd, (struct sockaddr*) &server_address);

    char clientMessage[] = "Hello from client!";
    send(client_fd, clientMessage, sizeof(clientMessage), 0);

    char buffer[BUFFER_SIZE] = {0};
    read(client_fd, buffer, BUFFER_SIZE-1);
    printf("Got response:\n%s\n", buffer);
    close(client_fd);
    return 0;
}