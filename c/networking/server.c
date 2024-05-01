#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
// #include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "commonDefinitions.h"

int createServerSocket(struct sockaddr_in address, socklen_t address_len)
{
    int server_fd;
    int opt = 1;

    // create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0)
    {
        perror("Could not create socket!");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)))
    {
        perror("setsockopt error!");
        exit(EXIT_FAILURE);
    }

    // bind socket to PORT
    int status = bind(server_fd, (struct sockaddr*) &address, address_len);
    if(status < 0)
    {
        perror("Could not bind socket to address!");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

void listenToConnectionsOnSocket(int server_fd, int max_queue_size)
{
    int status = listen(server_fd, max_queue_size);
    if(status < 0)
    {
        perror("Could not listen to connections!");
        exit(EXIT_FAILURE);
    }
    printf("Started listening to connection requests!\n");
}

int acceptConnectionOnSocket(int server_fd, struct sockaddr_in address, socklen_t address_len)
{
    int new_socket = accept(server_fd, (struct sockaddr*) &address, &address_len);
    if(new_socket < 0)
    {
        perror("could not accept connection!");
        exit(EXIT_FAILURE);
    }
    printf("accepted connection request...\n");
    return new_socket;
}

void handleConnection(int socket)
{
    // ssize_t valread;
    char buffer[BUFFER_SIZE] = {0};
    char serverResponse[] = "Hello, from server!";

    read(socket, buffer, BUFFER_SIZE -1);
    printf("Got message from client:\n%s\n", buffer);

    send(socket, serverResponse, sizeof(serverResponse), 0);
    printf("sent response to client! Closing socket...");
    close(socket);
}

int main()
{
    struct sockaddr_in address = getServerAddress();
    socklen_t address_len = sizeof(address);

    int server_fd = createServerSocket(address, address_len);
    listenToConnectionsOnSocket(server_fd, 5);

    int new_socket;

    while((new_socket = acceptConnectionOnSocket(server_fd, address, address_len)) > 0)
    {
        handleConnection(new_socket);
    }

    close(server_fd);

    return 0;
}