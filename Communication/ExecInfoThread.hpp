#ifndef __EXEC__INFO__THREAD__HPP__
#define __EXEC__INFO__THREAD__HPP__

#include <thread>

class ExecInfoThread{
	private:
	std::thread* _thread;
	bool _finished;
	
	public:
	ExecInfoThread();
	~ExecInfoThread();
	bool isFinished() const;
	std::thread* getThread();
	void setFinished(bool);
	void setThread(std::thread*);
};

#endif
