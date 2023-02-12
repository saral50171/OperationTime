#include <iostream>
#include <string>
#include <signal.h>
#include "operation_class.h"
#include "timer.cpp"

using namespace std;

#define OPERATIONS_NUM 5

static void init();
static void registerCtrlC();
static void signal_callback_handler(int signum);
static void runSession();
static void randAndWriteOperation(time_t sessionTime);

static std::string operationsStr[OPERATIONS_NUM] = {"undefined_operation", "operation_blocked", "waiting_operation", "operation_canceled", "operation_succeeded"};
static operationCls operations[OPERATIONS_NUM];
static Timer timer;

int main()
{
    init();
    registerCtrlC();
    runSession();
}


static void init()
{
    for (int i = 0; i < OPERATIONS_NUM; i++)
    {
        operations[i].setName(operationsStr[i]);
    }
}

static void registerCtrlC()
{
    struct sigaction sa = {0};
    sa.sa_handler = signal_callback_handler;
    sigemptyset(&(sa.sa_mask));
    sigaddset(&(sa.sa_mask), SIGINT);
    sigaction(SIGINT, &sa, NULL);
}

// Define the function to be called when ctrl-c (SIGINT) is sent to process
static void signal_callback_handler(int signum) 
{
    registerCtrlC();
    timer.stop();
    runSession();
}

static void runSession()
{
    cout << "press Y to start or ^c to stop" << endl;
    char ch;
    cin >> ch;
    while(ch != 'Y' && ch != 'y')
    {
        cout<<"unknown"<<endl;
        cin >> ch;
    }

    timer.start();
    time_t sessionTime = time(NULL);

    timer.setInterval([&]() {
        randAndWriteOperation(sessionTime);
    },1000); 

    timer.setInterval([&]() {
        timer.displayTime();
    },1); 

    while (1);
}

static void randAndWriteOperation(time_t sessionTime)
{
    int randIndex = rand()%5;
    srand(time(NULL));
    operations[randIndex].setTime(time(NULL));
    operations[randIndex].file.writeToFile(sessionTime, operations[randIndex].getTime(), operations[randIndex].getCounter());
}