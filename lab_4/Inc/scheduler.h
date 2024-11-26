/*
 * scheduler.h
 *
 *  Created on: Oct 18, 2024
 *      Author: ASUS
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct {
    void (*pTask)(void);  // Pointer to the task function
    uint32_t Delay;       // Delay until the function will run
    uint32_t Period;      // Interval between subsequent runs
    uint8_t RunMe;        // Indicates if the task is ready to run
    uint32_t TaskID;      // Unique task identifier
} sTasks;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

typedef unsigned char tByte;

void SCH_Init(void);
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
unsigned char SCH_Delete_Task(const tByte TASK_INDEX);
void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
