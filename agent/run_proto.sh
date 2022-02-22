#!/bin/bash

echo protoc --cpp_out=. ./src/proto/*.proto
protoc --cpp_out=. ./src/proto/*.proto

echo protoc --grpc_out=. ./src/proto/*.proto
protoc --grpc_out=.  --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./src/proto/*.proto

