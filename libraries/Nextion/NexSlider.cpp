/*
 * NexSlider.cpp
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#include "NexSlider.h"
#include <string>

NexSlider::NexSlider(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

bool NexSlider::getValue(uint32_t *number)
{
    std::string cmd = "get ";
    cmd += getObjName();
    cmd += ".val";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::setValue(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".val=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::Get_background_color_bco(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_background_color_bco(uint32_t number)
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

uint32_t NexSlider::Get_font_color_pco(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_font_color_pco(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".pco=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::Get_pointer_thickness_wid(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".wid";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_pointer_thickness_wid(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".wid=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::Get_cursor_height_hig(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".hig";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_cursor_height_hig(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".hig=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::getMaxval(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".maxval";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::setMaxval(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".maxval=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::getMinval(uint32_t *number)
{
    std::string cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".minval";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool NexSlider::setMinval(uint32_t number)
{
    char buf[10] = {0};
    std::string cmd;

    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".minval=";
    cmd += buf;
    sendCommand(cmd.c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


