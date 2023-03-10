/*
 * NexConfig.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#ifndef __NEXCONFIG_H__
#define __NEXCONFIG_H__
/**
 * @addtogroup Configuration
 * @{
 */

//#define DEBUG_SERIAL_ENABLE

/**
 * Define dbSerial for the output of debug messages.
 */
#define dbSerial Serial

/**
 * Define nexSerial for communicate with Nextion touch panel.
 */
#define nexSerial "huart1"

#ifdef DEBUG_SERIAL_ENABLE
#define dbSerialPrint(a)    dbSerial.print(a)
#define dbSerialPrintln(a)  dbSerial.println(a)
#define dbSerialBegin(a)    dbSerial.begin(a)
#else
#define dbSerialPrint(a)    do{}while(0)
#define dbSerialPrintln(a)  do{}while(0)
#define dbSerialBegin(a)    do{}while(0)
#endif

/**
 * @}
 */

#endif /* #ifndef __NEXCONFIG_H__ */
