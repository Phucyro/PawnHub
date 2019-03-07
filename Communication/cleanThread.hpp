#ifndef __CLEAN__THREAD__HPP__
#define __CLEAN__THREAD__HPP__

#include <iostream>
#include <list>
#include <iterator> 
#include "ExecInfoThread.hpp"

void delFinishedThread(std::list<ExecInfoThread*>& threadList){
	if (!threadList.empty()){
		ExecInfoThread* thread;
		std::list<ExecInfoThread*>::iterator it;
		for (it = threadList.begin(); it != threadList.end() && !threadList.empty(); ++it){
			std::cout<<(*it)<<std::endl;
			if (*it && (*it)->isFinished()){
				thread = *it;
				--it;
				threadList.remove(thread);
				thread->getThread()->join();
  				delete thread->getThread();
  				delete thread;
			}
		}
	}
}

#endif
