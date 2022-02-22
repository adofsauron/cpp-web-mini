#!/bin/bash

export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH


export TENANT_ID="ndb-influxdb"
export REPLICAS="1"
export POD_NAME="influxdb.svc.pod-1"
export MANAGE_URL="localhost:8080"
export CLUSTER_ID="cluster_influxdb"
export CHECK_CLUSTER_INTERVAL="10"
export SERVER_PORT="8080"


./agent

