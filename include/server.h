/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-28 08:14:05
 * @LastEditTime: 2022-02-03 10:27:27
 */
#ifndef SERVER_H_
#define SERVER_H_

#include "common.h"

using namespace std;

class CServer
{
public:
    CServer(int port, string ip);
    ~CServer();
    void run();
    static void RecvMsg(int conn);//child thread work function
private:
    int serv_port;
    int serv_sock;
    string serv_ip;
    vector<int> client_socks;
};

#endif // SERVER_H_