#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // close
#include <arpa/inet.h>  // sockaddr_in
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int clientSockets[MAX_CLIENTS];
int clientCount = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handleClient(void *clientSocket) {
    int sock = *(int *)clientSocket;
    char buffer[1024];
    int bytesRead;

    while ((bytesRead = read(sock, buffer, sizeof(buffer))) > 0) {
        buffer[bytesRead] = '\0';
        printf("Client %d: %s\n", sock, buffer);

        // Broadcast message to all clients
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < clientCount; i++) {
            if (clientSockets[i] != sock) {
                write(clientSockets[i], buffer, strlen(buffer));
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    close(sock);
    return NULL;
}

int main() {
    int serverSock, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    pthread_t tid;

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Server socket created.\n");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) != 0) {
        perror("Socket bind failed");
        exit(1);
    }
    printf("Socket bound to port %d.\n", PORT);

    if (listen(serverSock, 5) != 0) {
        perror("Listen failed");
        exit(1);
    }
    printf("Server listening...\n");

    while ((newSocket = accept(serverSock, (struct sockaddr *)&clientAddr, &addr_size)) > 0) {
        pthread_mutex_lock(&mutex);
        clientSockets[clientCount++] = newSocket;
        pthread_mutex_unlock(&mutex);

        pthread_create(&tid, NULL, handleClient, (void *)&newSocket);
    }

    close(serverSock);
    return 0;
}
