#ifndef _OPERATION_CLASS_H_
#define _OPERATION_CLASS_H_

#include <iostream>
#include <string>
#include "file_handler.h"

#define OPERATIONS_NUM 5

class operationCls
{
private:
    std::string name;
    time_t lastPrintTime;
    int counter = 0;
    static std::string operationsStr[OPERATIONS_NUM]; 

public:
    FileHandler file;
    
    operationCls();
    ~operationCls();
    void setName(int index);
    void setTime(time_t time);
    void setCounter(int cnt);

    std::string getName();
    time_t getTime();
    int getCounter();

    void saveOperationData(time_t sessionTime);

};

#endif //_OPERATION_CLASS_H_