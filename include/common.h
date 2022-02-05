/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-30 03:00:05
 * @LastEditTime: 2022-02-03 10:43:09
 */
#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <thread>
#include <vector>

using namespace std;
class CCommon
{
private:
    int serv_port;
    int serv_sock;
    string serv_ip;
    vector<int> client_socks;
public:
    CCommon(int port, string ip);
    ~CCommon();
    static void error_handle(std::string opt, std::string message)
    {
        //根据errno值获取失败原因并打印到终端
        perror(opt.c_str());
        std::cout << message << std::endl;
        exit(1);
    }
};

#endif