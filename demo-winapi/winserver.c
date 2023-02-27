#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

signed main()
{
    // 1. 网络服务初始化
    WSADATA wsaData; // web werver api 网络服务初始化
    int iResult;
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (iResult != 0)
    {
        printf("WSAStartup failed: %d\n", iResult);
        exit(1);
    }

    // 2.服务端需要获取自己对应注册端口的通信协议类型，地址信息等内容
    struct addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;       // ipv4地址
    hints.ai_socktype = SOCK_STREAM; // socket流
    hints.ai_protocol = IPPROTO_TCP; // tcp协议
    hints.ai_flags = AI_PASSIVE;     // 服务端被动绑定

    iResult = getaddrinfo(NULL, "8080", &hints, &result);
    // getaddrinfo函数提供从主机名到地址的独立于协议的转换
    // ，结果记录在result中

    if (iResult != 0) // iResult=0表示没有可用的端口
    {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        exit(1);
    }

    // 3.服务端需要创建一个适配相应端口信息的套接字（socket）
    SOCKET listen_socket = INVALID_SOCKET;
    listen_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    // socket函数根据getaddrinfo函数返回的信息
    // 创建一个**绑定**到相应端口的套接字

    if (listen_socket == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }

    // 4.服务端将本地地址和套接字绑定，也就意味着当前进程与端口绑定完成，
    // 此后获取到的端口地址信息不再会被使用，为了防止内存泄漏的风险需要将其释放
    iResult = bind(listen_socket, result->ai_addr, (int)result->ai_addrlen);
    // bind函数将本地地址与套接字相关联
    // 绑定完成后，释放不再使用的内存空间
    freeaddrinfo(result);

    if (iResult == SOCKET_ERROR)
    {
        printf("bind() failed: %d\n", WSAGetLastError());
        closesocket(listen_socket);
        WSACleanup();
        exit(1);
    }

    // 5.启动监听
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR)
    {
        printf("listen() failed: %d\n", WSAGetLastError());
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    // 6.建立连接
    SOCKET client_socket[2] = {INVALID_SOCKET};
    for (int i = 0; i < 2; ++i)
    {
        client_socket[i] = accept(listen_socket, NULL, NULL);

        if (client_socket[i] == INVALID_SOCKET)
        {
            printf("accept() failed: %d\n", WSAGetLastError());
            closesocket(listen_socket);
            WSACleanup();
            exit(1);
        }
    }
    printf("connection established!\n");

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    while (true)
    {
        iResult = recv(client_socket[0], buf, 1000, 0);
        if (iResult > 0)
        {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
            for (int i = 0; i < iResult; ++i)
            {
                if (buf[i] >= 'a' && buf[i] <= 'z')
                    buf[i] -= 32;
                else if (buf[i] == 0)
                    break;
            }

            int iSendResult = send(client_socket[0], buf, iResult, 0);
            if (iSendResult == SOCKET_ERROR)
            {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(client_socket[0]);
                closesocket(client_socket[1]);
                WSACleanup();
                exit(1);
            }
        }
        else if (iResult == 0)
        {
            printf("Connection closing...\n");
            system("pause");
        }
        else
        {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(client_socket[0]);
            closesocket(client_socket[1]);
            WSACleanup();
            exit(1);
        }

        iResult = recv(client_socket[1], buf, 1000, 0);
        if (iResult > 0)
        {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", buf);
            for (int i = 0; i <= 1000; i++)
            {
                if (buf[i] >= 'a' && buf[i] <= 'z')
                    buf[i] -= 32;
                else if (buf[i] == 0)
                    break;
            }
            int iSendResult = send(client_socket[1], buf, iResult, 0);
            if (iSendResult == SOCKET_ERROR)
            {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(client_socket[0]);
                closesocket(client_socket[1]);
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
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(client_socket[0]);
            closesocket(client_socket[1]);
            WSACleanup();
            exit(1);
        }
    }

    system("pause");

    return 0;
}