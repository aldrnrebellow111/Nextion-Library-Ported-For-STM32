/*
 * NexTimer.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Alvin
 */

#ifndef __NEXTIMER_H__
#define __NEXTIMER_H__

#include "NexTouch.h"
#include "NexHardware.h"
/**
 * @addtogroup Component
 * @{
 */

/**
 * NexTimer component.
 *
 * Commonly, you want to do something after set timer cycle and enable it,and the cycle value
 * must be greater than 50
 *
 */
class NexTimer: public NexTouch
{
public: /* methods */

    /**
     * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name);
     */
    NexTimer(uint8_t pid, uint8_t cid, const char *name);

    /**
     * Attach an callback function of timer respond event.
     *
     * @param timer - callback called with ptr when a timer respond event occurs.
     * @param ptr - parameter passed into push[default:NULL].
     * @return none.
     *
     * @note If calling this method multiply, the last call is valid.
     */
    void attachTimer(NexTouchEventCb timer, void *ptr = NULL);

    /**
     * Detach an callback function.
     *
     * @return none.
     */
    void detachTimer(void);

    /**
     * Get the value of timer cycle val.
     *
     * @param number - an output parameter to save the value of timer cycle.
     *
     * @retval true - success.
     * @retval false - failed.
     */
    bool getCycle(uint32_t *number);

    /**
     * Set the value of timer cycle val.
     *
     * @param number - the value of timer cycle.
     *
     * @retval true - success.
     * @retval false - failed.
     *
     * @warning  the cycle value must be greater than 50.
     */
    bool setCycle(uint32_t number);

    /**
     * contorl timer enable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
    bool enable(void);

    /**
     * contorl timer disable.
     *
     * @retval true - success.
     * @retval false - failed.
     */
    bool disable(void);

    /**
     * Get tim attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data
     */
    uint32_t Get_cycle_tim(uint32_t *number);

    /**
     * Set tim attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_cycle_tim(uint32_t number);
};
/**
 * @}
 */


#endif /* #ifndef __NEXTIMER_H__ */
