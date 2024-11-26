/*
 * scheduler.c
 *
 *  Created on: Oct 18, 2024
 *      Author: ASUS
 */
#include "scheduler.h"
#include "main.h"

enum error {
    ERROR_SCH_TOO_MANY_TASKS,
    ERROR_SCH_CANNOT_DELETE_TASK,
    ERROR_SCH_TASK_NOT_FOUND
};

enum return_code {
    RETURN_ERROR,
    RETURN_NORMAL
};

sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint32_t current_task_id = 1;
unsigned char Error_code_G = 0;

void SCH_Init(void) {
    for (unsigned char i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
    Error_code_G = 0;
    //current_task_id = 1;
}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
    unsigned char Index = 0;

    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
        Index++;
    }

    if (Index == SCH_MAX_TASKS) {
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        return SCH_MAX_TASKS;
    }

    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = DELAY;
    SCH_tasks_G[Index].Period = PERIOD;
    SCH_tasks_G[Index].RunMe = 0;
//    SCH_tasks_G[Index].TaskID = current_task_id++;
//
//    return SCH_tasks_G[Index].TaskID;
    return Index;
}
//unsigned char Index_0 = 0;
void SCH_Update(void) {
    for (unsigned char Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].pTask) {
            if (SCH_tasks_G[Index].Delay == 0) {
                SCH_tasks_G[Index].RunMe += 1;
                if (SCH_tasks_G[Index].Period) {
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            } else {
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
//    if (Index_0 < SCH_MAX_TASKS){
//        if (SCH_tasks_G[Index_0].pTask) {
//            if (SCH_tasks_G[Index_0].Delay == 0) {
//                SCH_tasks_G[Index_0].RunMe += 1;
//                if (SCH_tasks_G[Index_0].Period) {
//                    SCH_tasks_G[Index_0].Delay = SCH_tasks_G[Index_0].Period;
//                }
//            } else {
//                SCH_tasks_G[Index_0].Delay -= 1;
//            }
//        }
//
//        Index_0++;
//
//    }else if (Index_0 >= SCH_MAX_TASKS){
//    	Index_0 = 0;
//    }
//    return;
}

void SCH_Dispatch_Tasks(void) {
    for (unsigned char Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].RunMe > 0) {
            (*SCH_tasks_G[Index].pTask)();
            SCH_tasks_G[Index].RunMe -= 1;
            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
    }
}

unsigned char SCH_Delete_Task(const tByte TASK_INDEX) {
    if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
        return RETURN_ERROR;
    }

    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
//    SCH_tasks_G[TASK_INDEX].TaskID = 0;

    return RETURN_NORMAL;
}
//
//void SCH_Delete(uint32_t ID) {
//    for (unsigned char i = 0; i < SCH_MAX_TASKS; i++) {
//        if (SCH_tasks_G[i].TaskID == ID) {
//            SCH_Delete_Task(i);
//            return;
//        }
//    }
//    Error_code_G = ERROR_SCH_TASK_NOT_FOUND;
//}

