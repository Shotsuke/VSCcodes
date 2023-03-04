#include <iostream>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <queue>
using namespace std;
queue<string> request_queue;
SOCKET server_socket;
void maintainContact();
void inputController();
signed main()
{
    // 1.初始化网络服务，获取服务端相应端口信息
    printf("This is the client\n");
    WSADATA wsadata;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iResult != 0)
    {
        printf("WSAStartup failed: %d\n", iResult);
        exit(1);
    }

    addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_UNSPEC;
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
    server_socket = INVALID_SOCKET;
    ptr = result;
    server_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (server_socket == INVALID_SOCKET)
    {
        printf("socket() failed : %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    // 3.尝试与服务端连接
    if (connect(server_socket, ptr->ai_addr, (int)ptr->ai_addrlen) ==
        SOCKET_ERROR)
    // 该函数会阻塞等待连接建立成功或失败
    {
        printf("connect() failed\n");
        system("pause");
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }
    freeaddrinfo(result);

    printf("connection estabulished.\n");
    // 建立服务器通信线程（新建线程）
    CreateThread(NULL, (SIZE_T)NULL,
                 (LPTHREAD_START_ROUTINE)maintainContact,
                 NULL, (DWORD)0UL, NULL);
    // 建立客户端输入输出进程（此console）
    inputController();

    return 0;
}
void maintainContact()
{
    while (true)
    {
        if (!request_queue.empty())
        {
            char buf[1024];
            memset(buf, 0, sizeof(buf));
            for (int i = 0; i < request_queue.front().length(); ++i)
            {
                buf[i] = request_queue.front()[i];
            }
            int iResult = send(server_socket, buf,
                               request_queue.front().length(), 0);
            if (iResult == SOCKET_ERROR)
            {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(server_socket);
                WSACleanup();
                exit(1);
            }
            request_queue.pop();
            iResult = recv(server_socket, buf, 1000, 0);
            printf("request has been answered:%s.\n", buf);
        }
        Sleep(100);
    }
    return;
}
void inputController()
{
    while (printf("please input the string of request.\n"))
    {
        string buf;
        cin >> buf;
        request_queue.push(buf);
    }
    return;
}