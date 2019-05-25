/*	Scheduler
	Created by Eugenjus Margalikas, May 22, 2019
*/

#ifndef Sched_h
#define Sched_h

#include "Arduino.h"

#define TASK_COUNT 8
struct SchTask {
	void (*task)();
	unsigned long lastActive;
	unsigned long interval;
	unsigned long repeatCount;
	bool repeat;
	bool empty;
	SchTask();
	SchTask(void (*task)(),unsigned long lastActive, unsigned long interval, unsigned long repeatCount, bool repeat, bool empty);
	SchTask(void(*task)());
	//SchTask(void(*task)(),unsigned long interval);
	//SchTask(void(*task)(),unsigned long interval, unsigned long repeatCount);
	SchTask* withInterval(unsigned long interval);
	SchTask* withRepeatCount(unsigned long repeatCount);
	SchTask* repeatOnce();
	SchTask* withShift(unsigned long shift);
};

class Scheduler{
	public:
		Scheduler();
		SchTask* addTask(void (*task)());
		SchTask taskList[TASK_COUNT];
		void run();
		
};


#endif