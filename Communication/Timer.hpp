#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <unistd.h>

class Timer {
	bool started;

    //remaining time for the player
    int remaining_time;

    //checkpoints for duration
    std::chrono::steady_clock::time_point time_start;
    std::chrono::steady_clock::time_point time_end;

    std::chrono::steady_clock::time_point pause_start;
    std::chrono::steady_clock::time_point pause_end;

    //duration
    std::chrono::duration<double,std::milli> elapsed_time;
    std::chrono::duration<double,std::milli> pause_time;
    
    
    int get_elapsed_time();

public:
	Timer();
    Timer(int);
    ~Timer();
	
	operator std::string();		//update
	
    //game's time
    void start();
    void update();

    //pause's time
    void pause();				//update
    void unpause();
    int get_pause_time();
    
    //state informations
    bool is_paused() const;
    bool has_started() const;

    //game's utilities
    void remove(int);

    int get_remaining_time();	//update
    int get_minutes_left();
    int get_seconds_left();
    void reset(int);

};

#endif
