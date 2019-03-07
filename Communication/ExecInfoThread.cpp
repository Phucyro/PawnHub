#ifndef __EXEC__INFO__THREAD__CPP__
#define __EXEC__INFO__THREAD__CPP__

#include "ExecInfoThread.hpp"

ExecInfoThread::ExecInfoThread(): _thread(nullptr), _finished(false){}

ExecInfoThread::~ExecInfoThread(){
	_thread = nullptr;
}

bool ExecInfoThread::isFinished() const{
	return _finished;
}

std::thread* ExecInfoThread::getThread(){
	return _thread;
}

void ExecInfoThread::setFinished(bool val){
	_finished = val;
}

void ExecInfoThread::setThread(std::thread *thread){
	_thread = thread;
}

#endif
