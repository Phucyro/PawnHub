#include "Timer.hpp"

Timer::Timer(int maxTime): remaining_time(maxTime)
{

}


Timer::~Timer()
{

}

void Timer::start_time()
//start the timer at current time
{
    time_start = std::chrono::steady_clock::now();
}

void Timer::end_time()
//set end timer at current time
{
    time_end = std::chrono::steady_clock::now();
}

int Timer::get_elapsed_time()
//get time between start and end time
{
    elapsed_time = time_end - time_start;
    return int(elapsed_time.count());
}

void Timer::start_pause()
//set start pause timer at current time
{
    pause_start = std::chrono::steady_clock::now();
}

void Timer::end_pause()
//set end pause timer at current time
{
    pause_end = std::chrono::steady_clock::now();
}

int Timer::get_pause_time()
//get pause time
{
    pause_time = pause_end - pause_start;
    return int(pause_time.count());
}

void Timer::remove_time(int time)
//remove time from the remaining minutes
{
    remaining_time -= time;
    if (remaining_time < 0)
    {
        remaining_time = 0;
    }
}

int Timer::get_remaining_time()
//get remaining time total in seconds
{
    return remaining_time;
}

int Timer::get_minutes_left()
//get the minutes left
{
    return remaining_time / 60;
}

int Timer::get_seconds_left()
{
    return remaining_time % 60;
}

void Timer::reset_timer(int time)
{
    remaining_time = time;
}

void Timer::execution_example()
{
    unsigned int execution_time = 10000000; // unite en microsecondes -> 10 secondes

    std::cout << "REMAINING TIME:" << get_remaining_time() << "seconds = " << get_minutes_left() << " minutes et " << get_seconds_left() << "secondes" << std::endl;
    start_time();

    usleep(execution_time);

    end_time();

    std::cout << "ELAPSED TIME :" << get_elapsed_time() << std::endl;
    remove_time(get_elapsed_time());

    std::cout << "REMAINING TIME:" << get_remaining_time() << "seconds = " << get_minutes_left() << " minutes et " << get_seconds_left() << "secondes" << std::endl;
    reset_timer(300);

    std::cout << "REMAINING TIME:" << get_remaining_time() << "seconds = " << get_minutes_left() << " minutes et " << get_seconds_left() << "secondes" << std::endl;
}

