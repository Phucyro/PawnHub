#include "Timer.hpp"
Timer::Timer():Timer(0)
{

}


Timer::Timer(int maxTime): started(false), remaining_time(maxTime), time_start(), time_end(), pause_start(std::chrono::steady_clock::now()), pause_end(pause_start), elapsed_time(), pause_time()
{
	
}


Timer::~Timer()
{

}

Timer::operator std::string(){
	update();
	return  std::to_string(get_minutes_left()) + ":" + std::to_string(get_seconds_left());
}



void Timer::start()
{
    if (!started)
    {
    	time_start = std::chrono::steady_clock::now();
    	started = true;
    }
}

void Timer::update()
{
    if (started && !is_paused())
    {
    	time_end = std::chrono::steady_clock::now();
    	int time_passed = get_elapsed_time();
    	if (time_passed){
    		remove(time_passed);
    		time_start = time_end;
    	}
    }
}

int Timer::get_elapsed_time()
//get time between start and end time
{
    elapsed_time = time_end - time_start;
    return int(elapsed_time.count());
}



void Timer::pause()
{
    if (!is_paused())
    {
    	update();
    	pause_start = time_end;
    }
}

void Timer::unpause()
{
    if (is_paused())
    {
    	pause_end = std::chrono::steady_clock::now();
    	time_start = pause_end;
    }
}

int Timer::get_pause_time()
{
    pause_time = is_paused() ? pause_end - pause_start : std::chrono::steady_clock::now() - pause_start;
    return int(pause_time.count());
}



bool Timer::is_paused() const
{
	return pause_start > pause_end;
}

bool Timer::has_started() const
{
	return started;
}



void Timer::remove(int time)
{
    remaining_time -= time;
    if (remaining_time < 0)
    {
        remaining_time = 0;
    }
}

int Timer::get_remaining_time()
//in seconds
{
    update();
    return remaining_time;
}

int Timer::get_minutes_left()
{
    return remaining_time / 60;
}

int Timer::get_seconds_left()
{
    return remaining_time % 60;
}

void Timer::reset(int time)
{
    remaining_time = time;
    started = false;
    pause_start = pause_end;
}

