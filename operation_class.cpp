#include <iostream>
#include "operation_class.h"
#include "cursor_handler.h"

using namespace std;

std::string operationCls::operationsStr[OPERATIONS_NUM] = {"undefined_operation", "operation_blocked", "waiting_operation", "operation_canceled", "operation_succeeded"};

operationCls::operationCls()
{
    counter = 0;
}

operationCls::~operationCls()
{
}

void operationCls::setName(int index)
{
    name = operationsStr[index];
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

void operationCls::saveOperationData(time_t sessionTime)
{
    gotoNextLine();
    cout << getName() << endl;
    setTime(time(NULL));
    if(getName() == "operation_succeeded" || getName() == "operation_blocked")
    {
        setCounter(getCounter()+1);
    }
    file.writeToFile(sessionTime, getTime(), getCounter());
}
