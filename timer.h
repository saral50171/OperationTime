#ifndef _TIMER_H_
#define _TIMER_H_

#include <thread>

class Timer {
    bool clear = false;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int milisec = 0;

public:
    void increseTime();
    
    template<typename Function>
    void setTimeout(Function function, int delay) {
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
    void setInterval(Function function, int interval) {
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

    void displayTime();

    void start();
    void stop();

    Timer();
    ~Timer();
};

#endif //_TIMER_H_