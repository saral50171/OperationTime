#include <iostream>
#include <string>
#include <fstream>
#include "file_handler.h"

using namespace std;

void FileHandler::writeToFile(time_t sessionTime, time_t printTime, int counter)
{
    file.open(fileName, ios::in | ios::out | ios::app);
    if (!file)
    {
        cout << "failed to open - not exsist, create it now" << endl;
        file.open(fileName, ios::in | ios::out | ios::trunc);
    }

    std::string line;
    std::string matchPattern = "counter: ";
    std::string tmp; 
    int cnt;

    while (getline(file, line))
    { 
        if (line.find(sessionTime) != string::npos)
        {
            getline(file, line); 
            tmp = line.substr(matchPattern.size());
            cnt = (int)strtol(tmp.c_str(), nullptr, 10) + 1;
            file << matchPattern + std::to_string(cnt);
        }
    }

    file << "session start time: " << ctime(&sessionTime) << endl;
    file << "counter: " << counter << endl;
    file << "random time: " << ctime(&printTime) << endl;

    file.close();
}

void FileHandler::setFileName(std::string name)
{
    fileName = "files/" + name + ".log";
}

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}
