#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <unistd.h>

using namespace std;

class Timer {
    bool clear = false;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int milisec = 0;

    void increseTime();
    void gotoxy(int x,int y);

public:
    template<typename Function>
    void setTimeout(Function function, int delay);

    template<typename Function>
    void setInterval(Function function, int interval);

    void displayTime();

    void start();
    void stop();

    Timer();
    ~Timer();
};

template<typename Function>
void Timer::setTimeout(Function function, int delay) {
    this->clear = false;
    std::thread t([=]() {
        if(this->clear) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(this->clear) return;
        function();
    });
    t.detach();
}

template<typename Function>
void Timer::setInterval(Function function, int interval) {
    this->clear = false;
    std::thread t([=]() {
        while(true) {
            if(this->clear) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if(this->clear) return;
            function();
        }
    });
    t.detach();
}

void Timer::start()
{
    clear = false;
    hours = 0;
    minutes = 0;
    seconds = 0;
    milisec = 0;
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
    gotoxy(0,0);
    cout << setfill('0') << setw(2) << this->hours << ":";
    cout << setfill('0') << setw(2) << this->minutes << ":";
    cout << setfill('0') << setw(2) << this->seconds << ":";
    cout << setfill('0') << setw(2) << this->milisec <<  endl;
}

void Timer::gotoxy(int x,int y)    
{
    printf("\033[%d;%dH", y, x);
}
