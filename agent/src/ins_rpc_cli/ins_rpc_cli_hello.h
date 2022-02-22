#ifndef __INS_RPC_CLI_HELLO_H__
#define __INS_RPC_CLI_HELLO_H__

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "../proto/hello.grpc.pb.h"

class ServiceHelloClient {
public:
    virtual ~ServiceHelloClient() {}

public:
  ServiceHelloClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(ServiceHello::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user) {
    // Data we are sending to the server.
    HelloRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    HelloReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->SayHello(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

private:
  std::unique_ptr<ServiceHello::Stub> stub_;
};

#endif /* __INS_RPC_CLI_HELLO_H__ */
