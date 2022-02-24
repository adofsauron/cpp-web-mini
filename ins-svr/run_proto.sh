#!/bin/bash

HERE=`pwd`

cd src/proto

echo protoc --cpp_out=. ./*.proto
protoc --cpp_out=. ./*.proto

echo protoc --grpc_out=. ./*.proto
protoc --grpc_out=.  --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./*.proto


cd $HERE
