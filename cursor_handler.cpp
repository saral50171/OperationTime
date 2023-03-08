#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include "cursor_handler.h"

using namespace std;

static int counter = 0;

void gotoNextLine()
{
    counter++;
    printf("\033[%d;%dH", counter, 0);
}

void resetCounter()
{
    counter = 0;
}
