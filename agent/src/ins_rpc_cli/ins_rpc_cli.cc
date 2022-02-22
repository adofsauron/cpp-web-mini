#include <iostream>
#include <memory>
#include <string>

#include "ins_rpc_cli.h"

const static std::string INS_RPC_UNIX_PATH = "unix:/data/influxdb-unix-rpc.socket";

int RunRPCHello() 
{
    std::string target_str(INS_RPC_UNIX_PATH);
    ServiceHelloClient cli_hello(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
        
    std::string user("world");
    std::string reply = cli_hello.SayHello(user);
    std::cout << "ServiceHello received: " << reply << std::endl;

    return 0;
}
