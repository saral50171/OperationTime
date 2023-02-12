#ifndef _OPERATION_CLASS_H_
#define _OPERATION_CLASS_H_

#include <iostream>
#include <string>
#include "file_handler.h"

class operationCls
{
private:
    std::string name;
    time_t lastPrintTime;
    int counter = 0;

public:
    FileHandler file;
    
    operationCls();
    ~operationCls();
    void setName(std::string name);
    void setTime(time_t time);
    void setCounter(int cnt);

    std::string getName();
    time_t getTime();
    int getCounter();
};

#endif //_OPERATION_CLASS_H_