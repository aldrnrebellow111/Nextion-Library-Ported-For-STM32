/*
 * NexVariable.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#ifndef __NEXVARRIABLE_H__
#define __NEXVARRIABLE_H__

#include "NexTouch.h"
#include "NexHardware.h"
/**
 * @addtogroup Component
 * @{
 */

/**
 * NexButton component.
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref NexTouch::attachPop to satisfy your purpose.
 *
 * @warning Please do not call @ref NexTouch::attachPush on this component, even though you can.
 */
class NexVariable: public NexTouch
{
public: /* methods */

    /**
     * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name);
     */
    NexVariable(uint8_t pid, uint8_t cid, const char *name);

    /**
     * Get text attribute of component.
     *
     * @param buffer - buffer storing text returned.
     * @param len - length of buffer.
     * @return The real length of text returned.
     */
    uint32_t getText(char *buffer, uint32_t len);

    /**
     * Set text attribute of component.
     *
     * @param buffer - text buffer terminated with '\0'.
     * @return true if success, false for failure.
     */
    bool setText(const char *buffer);

    /**
     * Get val attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data
     */
    uint32_t getValue(uint32_t *number);

    /**
     * Set val attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool setValue(uint32_t number);
};
/**
 * @}
 */


#endif /* #ifndef __NEXVARRIABLE_H__*/
