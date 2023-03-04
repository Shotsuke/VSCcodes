#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
using namespace std;
void maintainContact(SOCKET *client_socket);
void buildconnection(SOCKET *listen_socket);
signed main()
{
    printf("This is the server.\n");
    WSADATA wsadata;
    int iResult;
    // 1.初始化
    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iResult != 0)
    {
        printf("WSAStartup failed : %d\n", iResult);
        exit(1);
    }
    // 2.搜寻地址结果
    addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    iResult = getaddrinfo("127.0.0.1", "8080", &hints, &result);
    if (iResult != 0)
    {
        printf("Getaddrinfo failed : %d\n", iResult);
        WSACleanup();
        exit(1);
    }
    // 3.初始化套接字
    SOCKET listen_socket = INVALID_SOCKET;
    listen_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listen_socket == INVALID_SOCKET)
    {
        printf("listen_socket failed : %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }
    // 4.连接套接字与地址
    iResult = bind(listen_socket, result->ai_addr, (int)result->ai_addrlen);
    freeaddrinfo(result);
    if (iResult == SOCKET_ERROR)
    {
        printf("Bind failed : %d\n", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
    // 5.置入侦听
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR)
    {
        printf("Listen failed : %d\n", WSAGetLastError());
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    // 6.不断读入新线程
    buildconnection(&listen_socket);
    return 0;
}
void buildconnection(SOCKET *listen_socket)
{
    while (true)
    { // 持续读入新的客户端
        SOCKET *client_socket = (SOCKET *)malloc(sizeof(SOCKET));
        *client_socket = INVALID_SOCKET;
        *client_socket = accept(*listen_socket, NULL, NULL);
        if (*client_socket == INVALID_SOCKET)
        {
            printf("Accept failed : %d\n", WSAGetLastError());
            closesocket(*listen_socket);
            WSACleanup();
            exit(1);
        }

        printf("Connection established.\n");
        // 为新的客户端创建新的线程
        CreateThread(NULL, (SIZE_T)NULL,
                     (LPTHREAD_START_ROUTINE)maintainContact, client_socket,
                     (DWORD)0UL, NULL);
    }
}
void maintainContact(SOCKET *client_socket)
{
    char buf[1024];
    memset(buf, 0, sizeof(buf));

    while (true)
    {
        int iResult = recv(*client_socket, buf, 1000, 0); // 1000为设置上限
        if (iResult > 0)
        {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
            for (int i = 0; i < iResult; i++)
            {
                if (buf[i] >= 'a' && buf[i] <= 'z')
                    buf[i] -= 32;
                else if (buf[i] == 0)
                    break;
            }

            int iSendResult = send(*client_socket, buf, iResult, 0);
            if (iSendResult == SOCKET_ERROR)
            {
                printf("Send failed : %d\n", WSAGetLastError());
                closesocket(*client_socket);
                WSACleanup();
                exit(1);
            }
        }
        else if (iResult == 0)
        {
            printf("Connection closing ...\n");
            system("pause");
        }
        else
        {
            printf("Recv failed : %d\n", WSAGetLastError());
            closesocket(*client_socket);
            WSACleanup();
            exit(1);
        }
    }
    return;
}