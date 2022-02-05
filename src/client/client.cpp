/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-30 02:56:12
 * @LastEditTime: 2022-02-05 09:25:32
 */
#include "client.h"

CClient::CClient(int port, string ip):
                    serv_port(port), serv_ip(ip)
{
    cout << "client constructor..." << endl;
}

CClient::~CClient()
{
    close(client_sock);
}

void CClient::RecvMsg(int conn){
    char buffer[1000];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);
        if (len <= 0)
            break;
        cout <<"recv buffer "<< buffer <<"from conn "<< conn <<endl;
    }
}

void CClient::SendMsg(int conn){
    char buffer[100];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        cin>>buffer;
        int len = send(conn, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "exit") == 0 || len <= 0)
            break;
    }
}

void CClient::run(){
    //socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    //sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    //server ip and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serv_port);
    servaddr.sin_addr.s_addr = inet_addr(serv_ip.c_str());
    
    //connect
    if (connect(client_sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        CCommon::error_handle("socket", "connect() error.");
    }
    
    //send thread
    thread send_t(SendMsg, client_sock);
    send_t.join();

    //recv thread
    thread recv_t(RecvMsg, client_sock);
    recv_t.join();

    return;
}
