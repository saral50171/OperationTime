#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include "file_handler.h"
#include "cursor_handler.h"

using namespace std;

void FileHandler::writeToFile(time_t sessionTime, time_t printTime, int counter)
{
    file.open(fileName, ios::in | ios::out | ios::app);
    if (!file)
    {
        gotoNextLine();
        cout << "failed to open - not exsist, create it now" << endl;
        file.open(fileName, ios::in | ios::out | ios::trunc);
    }

    file << "session start time: " << ctime(&sessionTime);
    file << "random time: " << ctime(&printTime);

    if(fileName.find("operation_succeeded")!= std::string::npos || fileName.find("operation_blocked")!= std::string::npos)
    {
        file << "counter: " << counter << endl;
    }

    file.close();
}

void FileHandler::setFileName(std::string name)
{
    const char* dir;

    dir = "files/";
    struct stat sb;

    if (stat(dir, &sb) != 0 || !S_ISDIR(sb.st_mode)) 
    {
        gotoNextLine();
        cout << "there is no files dir. save file on current dir." << endl;
        fileName = name + ".log";
    } 
    else 
    {
        fileName = "files/" + name + ".log";
    }

}

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}
