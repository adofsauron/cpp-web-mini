#include <boost/thread.hpp>
#include <boost/timer/progress_display.hpp>

#include "../http/httpserver.h"
#include "../coroutine/coroutine.h"
#include "../proc/heart_beat.h"
#include "../logger/logger.h"
#include "../config/config.h"

#define THREADS_NUM_MIN 1
#define THREADS_NUM_MAX 4

int main()
{
    InitResource();

    go StartHttpServer;
    go StartHeartBeat;

    LogInstance().info("agent run...");
    while (!g_Scheduler.IsEmpty()) {
        g_Scheduler.Start(THREADS_NUM_MIN, THREADS_NUM_MAX);
    }

    LogInstance().info("agent run over");
    return 0;
}

void InitResource()
{
    InitLogInstance();
    InitConfig();
}


