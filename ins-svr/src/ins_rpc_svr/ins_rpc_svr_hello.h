#ifndef __INS_RPC_SVR_HELLO_H__
#define __INS_RPC_SVR_HELLO_H__

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

#include "../proto/hello.grpc.pb.h"
#include "../logger/logger.h"


class ServiceHelloSvrImpl final : public ServiceHello::Service 
{
public:
    virtual ~ServiceHelloSvrImpl() {}

public:
  grpc::Status SayHello(grpc::ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {

    LogInstance().info("iServiceHelloSvrImpl::SayHello");

    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return grpc::Status::OK;
  }
};


#endif /* __INS_RPC_SVR_HELLO_H__ */