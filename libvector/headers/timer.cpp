#include <ctime>
#include <iostream>
#include "timer.h"

void start_timer(double& clock_init){
    clock_init = clock();
}

void stop_timer(double& clock_stop){
    clock_stop = clock();
}

void printTime(const double& clock_init,
        const double& clock_stop){
    std::cout << "\t\tSecs.: " << (clock_stop - clock_init)/CLOCKS_PER_SEC << '\n';
}
