/*
 * NexWaveform.cpp
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#include "NexWaveform.h"
#include <string>

NexWaveform::NexWaveform(uint8_t pid, uint8_t cid, const char *name)
    :NexObject(pid, cid, name)
{
}

bool NexWaveform::addValue(uint8_t ch, uint8_t number)
{
    char buf[32] = {0};

    if (ch > 3)
    {
        return false;
    }

    sprintf(buf, "add %u,%u,%u", getObjCid(), ch, number);

    sendCommand(buf);
    return true;
}

bool NexWaveform::Clear(uint8_t ch)
{
    char buf[32] = {0};

    if (ch > 3)
    {
        return false;
    }

    sprintf(buf, "cle %u,%u,%u", getObjCid(), ch);

    sendCommand(buf);
    return true;
}

uint32_t NexWaveform::Get_background_color_bco(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexWaveform::Set_background_color_bco(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".bco=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexWaveform::Get_grid_color_gdc(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdc";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexWaveform::Set_grid_color_gdc(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdc=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexWaveform::Get_grid_width_gdw(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdw";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexWaveform::Set_grid_width_gdw(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdw=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexWaveform::Get_grid_height_gdh(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdh";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexWaveform::Set_grid_height_gdh(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdh=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexWaveform::Get_channel_0_color_pco0(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco0";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexWaveform::Set_channel_0_color_pco0(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".pco0=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}




