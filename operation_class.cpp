#include <iostream>
#include "operation_class.h"

using namespace std;

operationCls::operationCls()
{
    counter = 0;
}

operationCls::~operationCls()
{
}

void operationCls::setName(std::string name)
{
    name = name;
    file.setFileName(name);
}

void operationCls::setTime(time_t time)
{
    lastPrintTime = time;
}

void operationCls::setCounter(int cnt)
{
    counter = cnt;
}

std::string operationCls::getName()
{
    return name;
}

time_t operationCls::getTime()
{
    return lastPrintTime;
}

int operationCls::getCounter()
{
    return counter;
}

