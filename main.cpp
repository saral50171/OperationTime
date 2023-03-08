#include <iostream>
#include <string>
#include <signal.h>
#include <string.h>
#include "operation_class.h"
#include "timer.h"
#include "cursor_handler.h"

using namespace std;

static void init();
static void registerCtrlC();
static void signal_callback_handler(int signum);
static void runSession();
static void randOperation(time_t sessionTime);

static Timer timer;
static operationCls operations[OPERATIONS_NUM];
static bool shouldRestartSession = false;

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
        operations[i].setName(i);  
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

static void signal_callback_handler(int signum) 
{
    gotoNextLine();
    cout << "I'm here :)" << endl;
    shouldRestartSession = true;
}

static void runSession()
{
    char ch;
 
    while(1)
    {
        /***********************************************************/
        // init session
        /***********************************************************/
        system("clear");
        resetCounter();
        gotoNextLine();
        cout << "press Y to start or ^c to stop" << endl;
        cin >> ch;
        if(ch != 'Y' && ch != 'y')
        {
            gotoNextLine();
            cout<<"unknown, exit"<<endl;    
            exit(0);
        }

        for (int i = 0; i < OPERATIONS_NUM; i++)
        {
            operations[i].setCounter(0);    
        }
        
        /***********************************************************/
        // start session
        /***********************************************************/
        timer.start();
        time_t sessionTime = time(NULL);

        timer.setInterval([&]() {
            randOperation(sessionTime);
        },1000); 

        timer.setInterval([&]() {
            timer.increseTime();
        },1); 

        while(!shouldRestartSession);

        /***********************************************************/
        // stop session
        /***********************************************************/
        timer.stop();
        shouldRestartSession = false;
    }
}

void randOperation(time_t sessionTime)
{
    int randIndex = rand()%OPERATIONS_NUM; 
    srand(time(NULL));
    operations[randIndex].saveOperationData(sessionTime);
}
