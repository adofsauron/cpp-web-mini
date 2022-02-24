#include <boost/thread.hpp>
#include <boost/timer/progress_display.hpp>

#include "../http/httpserver.h"
#include "../coroutine/coroutine.h"
#include "../proc/heart_beat.h"
#include "../logger/logger.h"
#include "../ins_rpc_svr/ins_rpc_svr.h"
#include "run.h"

#define THREADS_NUM_MIN 1
#define THREADS_NUM_MAX 4

int main()
{
    InitResource();

    go StartInsRPCServer;
    go StartHeartBeat;

    LogInstance().info("ins-rpc run...");
    while (!g_Scheduler.IsEmpty()) {
        g_Scheduler.Start(THREADS_NUM_MIN, THREADS_NUM_MAX);
    }

    LogInstance().info("ins-rpc run over");
    return 0;
}

void InitResource()
{
    InitLogInstance();
}

