/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-28 08:14:27
 * @LastEditTime: 2022-02-03 10:44:04
 */
#include "server.h"

CServer::CServer(int port, string ip):serv_port(port), serv_ip(ip)
{
    cout <<"consturctor"<<endl;
}

CServer::~CServer(){
    for (auto conn:client_socks)
    {
        close(conn);
    }
    close(serv_sock);
}

void CServer::run(){
    int ret;
    struct sockaddr_in serv_adr;
    struct sockaddr_in client_adr;
    socklen_t adr_size = sizeof(client_adr);
    //创建socket套接字
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock < 0)
    {
        CCommon::error_handle("socket", "socket() error.");
    }

    //初始化服务器套接字参数，设置网卡IP 和端口号
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(serv_ip.c_str());
    serv_adr.sin_port = htons(serv_port);

    //绑定端口
    ret = bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    if(ret < 0)
    {
        CCommon::error_handle("socket", "bind() error.");
    }

    //监听TCP端口号
    ret = listen(serv_sock, 5);
    if(ret < 0)
    {
        CCommon::error_handle("socket", "listen() error.");
    }

    while (1)
    {
        int conn = accept(serv_sock, (struct sockaddr*)&client_adr, &adr_size);
        if(conn < 0)
        {
            //接收请求失败，继续工作
            CCommon::error_handle("socket", "accept() error.");
            continue;
        }
        cout <<"connect success fd is :"<<conn<<endl;
        client_socks.push_back(conn);
        thread t(CServer::RecvMsg, conn);
        t.detach();//join is block
    }
}

void CServer::RecvMsg(int conn){
    char buffer[100];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "exit") == 0 || len <= 0)
        {
            break;
            cout <<"recv buffer "<< buffer <<"from conn "<< conn <<endl;
        }
    }
}