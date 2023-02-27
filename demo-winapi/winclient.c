#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

signed main()
{
    // 1.初始化网络服务，获取服务端相应端口信息
    WSADATA wsadata;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iResult != 0)
    {
        printf("WSAStartup failed: %d\n", iResult);
        exit(1);
    }

    struct addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; // IPV4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo("127.0.0.1", "8080", &hints, &result);
    if (iResult != 0)
    {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        exit(1);
    }

    // 2.客户端根据得到的信息构建服务端套接字
    SOCKET server_socket = INVALID_SOCKET;
    ptr = result;
    server_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (server_socket == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    // 3.尝试与服务端连接
    if (connect(server_socket, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR)
    {
        printf("connect() failed\n");
        system("pause");
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }
    freeaddrinfo(result);

    printf("please input a string.\n");
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    while (scanf("%s", buf))
    {
        iResult = send(server_socket, buf, strlen(buf), 0);
        if (iResult == SOCKET_ERROR)
        {
            printf("send failed: %d\n", WSAGetLastError());
            closesocket(server_socket);
            WSACleanup();
            exit(1);
        }

        printf("Bytes send: %d\n", iResult);
        iResult = recv(server_socket, buf, 1000, 0);
        if (iResult > 0)
        {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
        }
        else if (iResult == 0)
        {
            printf("Connection closing ...\n");
            system("pause");
        }
        else
        {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(server_socket);
            WSACleanup();
            exit(1);
        }
        system("pause");
    }

    return 0;
}