#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <unistd.h>
#include "timer.h"

using namespace std;

void Timer::start()
{
    clear = false;
    hours = 0;
    minutes = 0;
    seconds = 0;
    milisec = 0;
    system("clear");
}

void Timer::stop()
{
    this->clear = true;
}

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::increseTime() {
    this->milisec++;
    if(this->milisec == 1000)
    {
        this->seconds++;
        if(this->seconds == 60)
        {
            this->minutes++;
            if(this->minutes == 60)
            {
                this->hours++;
                this->minutes = 0;
            }
            this->seconds = 0;
        }
        this->milisec = 0;
    }
    this->displayTime();
}

void Timer::displayTime()
{
    printf("\033[%d;%dH", 0, 0);

    cout << setfill('0') << setw(2) << this->hours << ":";
    cout << setfill('0') << setw(2) << this->minutes << ":";
    cout << setfill('0') << setw(2) << this->seconds << ":";
    cout << setfill('0') << setw(2) << this->milisec <<  endl;
}

