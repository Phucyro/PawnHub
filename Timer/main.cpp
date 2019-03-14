#include "Timer.cpp"

#include <iostream>
#include <unistd.h>



int main() {

    unsigned int microseconds = 100000000;

    Timer* test = new Timer(300);
    std::cout << "REMAINING TIME:" << test->get_remaining_time() << "seconds = " << test->get_minutes_left() << " minutes et " << test->get_seconds_left() << "secondes" << std::endl;
    test->start_time();
    usleep(microseconds);
    test->end_time();
    test->remove_time(test->get_elapsed_time());
    std::cout << "REMAINING TIME:" << test->get_remaining_time() << "seconds = " << test->get_minutes_left() << " minutes et " << test->get_seconds_left() << "secondes" << std::endl;
}