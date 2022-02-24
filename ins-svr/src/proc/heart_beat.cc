#include <iostream>
#include <thread>
#include <unistd.h>

#include "heart_beat.h"
#include "../logger/logger.h"
#include "../coroutine/coroutine.h"

static bool __runHeartBeat = true;

void StartHeartBeat()
{
    while (__runHeartBeat)
    {
        co_sleep(1000);

        RunHeartBeat();
        co_yield;
    }
}

void StopHeartBeat()
{
    __runHeartBeat = false;
}

void RunHeartBeat()
{
    LogInstance().debug("heart beat...");
}
