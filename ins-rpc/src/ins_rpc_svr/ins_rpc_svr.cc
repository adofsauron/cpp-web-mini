#include <iostream>
#include <memory>
#include <string>
#include <functional>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "../coroutine/coroutine.h"
#include "../proto/hello.grpc.pb.h"

#include "../logger/logger.h"
#include "ins_rpc_svr_hello.h"

const static std::string INS_RPC_UNIX_PATH = "unix:/data/influxdb-unix-rpc.socket";

void StartInsRPCServer()
{
    std::string server_address(INS_RPC_UNIX_PATH);

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    ServiceHelloSvrImpl svc_hello;
    builder.RegisterService(&svc_hello);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    LogInstance().info("grpc::Server listening on [%s] ...", server_address.c_str());

    co_yield;
    server->Wait();
}

