/*
 * NexHardware.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#ifndef __NEXHARDWARE_H__
#define __NEXHARDWARE_H__

#include "main.h"

#include "NexConfig.h"
#include "NexTouch.h"

/**
 * @addtogroup CoreAPI
 * @{
 */

/**
 * Init Nextion.
 *
 * @return true if success, false for failure.
 */
bool nexInit(UART_HandleTypeDef *huart, uint32_t baudrate);

/**
 * Listen touch event and calling callbacks attached before.
 *
 * Supports push and pop at present.
 *
 * @param nex_listen_list - index to Nextion Components list.
 * @return none.
 *
 * @warning This function must be called repeatedly to response touch events
 *  from Nextion touch panel. Actually, you should place it in your loop function.
 */
void nexLoop(NexTouch *nex_listen_list[]);

/**
 * @}
 */

bool recvRetNumber(uint32_t *number, uint32_t timeout = 100);
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = 100);
void sendCommand(const char* cmd);
bool recvRetCommandFinished(uint32_t timeout = 100);

#endif /* #ifndef __NEXHARDWARE_H__ */