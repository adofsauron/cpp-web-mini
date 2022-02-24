#!/bin/bash

HERE=`pwd`

# protobuf

cd third_party
rm protobuf-3.19.4 -rf
tar -xzvf protobuf-all-3.19.4.tar.gz

cd protobuf-3.19.4/

./configure

make -j"$(nproc)"
make install

cd ..
rm protobuf-3.19.4 -rf

# libgo

cd $HERE

cd third_party
rm libgo-3.1-stable -rf
tar -xzvf libgo-3.1-stable.tar.gz

cd libgo-3.1-stable

rm ./build -rf
mkdir -p ./build
cd ./build

cmake -DDISABLE_HOOK=on  ..

make -j"$(nproc)"
make install

cd ../..
rm libgo-3.1-stable -rf

# log4cpp

cd third_party
rm log4cpp-2.9.1 -rf
tar -xzvf log4cpp-2.9.1.tar.gz

cd log4cpp-2.9.1

rm ./build -rf
mkdir -p ./build
cd ./build

cmake ..

make -j"$(nproc)"
make install

cd ../..
rm log4cpp-2.9.1 -rf

# grpc

cd $HERE

cd third_party
rm grpc -rf
tar -xzvf grpc.tar.gz
cd grpc

rm ./build -rf
mkdir -p ./build
cd ./build

cmake ..

make -j"$(nproc)"
make install

cd ../..
rm ./grpc -rf

# boost

cd $HERE

cd third_party
rm boost -rf
tar -xzvf boost.tar.gz

cd boost
./bootstrap.sh

./b2

./b2 header

./b2 install

cd ..
rm boost -rf

# over

cd $HERE


