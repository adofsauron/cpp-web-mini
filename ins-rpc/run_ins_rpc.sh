#!/bin/bash

export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

rm /data/influxdb-unix-rpc.socket -rf

./ins_rpc

