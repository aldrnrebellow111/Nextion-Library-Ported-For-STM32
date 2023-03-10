/*
 * NexTimer.cpp
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#include "NexTimer.h"
#include <string>

NexTimer::NexTimer(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

void NexTimer::attachTimer(NexTouchEventCb timer, void *ptr)
{
    NexTouch::attachPop(timer, ptr);
}

void NexTimer::detachTimer(void)
{
    NexTouch::detachPop();
}

bool NexTimer::getCycle(uint32_t *number)
{
    std::string cmd = "get ";
    cmd += getObjName();
    cmd += ".tim";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexTimer::setCycle(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;
    if (number < 50)
    {
        number = 50;
    }
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".tim=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool NexTimer::enable(void)
{
    char buf[10] = {0};
    std::string cmd;
    utoa(1, buf, 10);
    cmd += getObjName();
    cmd += ".en=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool NexTimer::disable(void)
{
    char buf[10] = {0};
    std::string cmd;
    utoa(0, buf, 10);
    cmd += getObjName();
    cmd += ".en=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexTimer::Get_cycle_tim(uint32_t *number)
{
    std::string cmd = "get ";
    cmd += getObjName();
    cmd += ".tim";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexTimer::Set_cycle_tim(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;
    if (number < 8)
    {
        number = 8;
    }
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".tim=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}




