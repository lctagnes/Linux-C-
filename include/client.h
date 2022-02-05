/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-30 02:56:03
 * @LastEditTime: 2022-02-03 11:49:51
 */
#ifndef CLIENT_H_
#define CLIENT_H_

#include "common.h"

using namespace std;

class CClient
{
public:
    CClient(int port, string ip);
    ~CClient();
    void run();
    static void SendMsg(int conn);
    static void RecvMsg(int conn);
private:
    int serv_port;
    int client_sock;
    string serv_ip;
};

#endif 