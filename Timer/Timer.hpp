#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>
#include <ctime>

class Timer {
    //remaining time for the player
    int remaining_time;

    //checkpoints for duration
    std::chrono::steady_clock::time_point time_start;
    std::chrono::steady_clock::time_point time_end;

    std::chrono::steady_clock::time_point pause_start;
    std::chrono::steady_clock::time_point pause_end;

    //duration
    std::chrono::duration<double> elapsed_time;
    std::chrono::duration<double> pause_time;

public:

    Timer(int);
    ~Timer();

    //game's time
    void start_time();
    void end_time();
    int get_elapsed_time();

    //pause's time
    void start_pause();
    void end_pause();
    int get_pause_time();

    // game's utilities
    void remove_time(int);
    int get_remaining_time();
    int get_minutes_left();
    int get_seconds_left();
};

#endif