/*
 * @Descripttion: lct
 * @version: 1.0
 * @Author: Lct
 * @Date: 2022-01-28 08:14:27
 * @LastEditTime: 2022-02-03 11:34:31
 */
#include "server.h"

int main(int argc, char* argv[]){
    // cout << "main0..." << argv[0]  <<endl;
    // cout << "main1..." << argv[1]  <<endl;


    if (argv[1] == "server")
    {
        cout << "sss..." << endl;
        CServer server(std::atoi(argv[2]), argv[3]);
        server.run();
    }
    
    return 0;
}