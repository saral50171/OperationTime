#ifndef _FILE_DECODER_H_
#define _FILE_DECODER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class FileHandler
{
    fstream file;
    std::string fileName;

public:
    FileHandler();
    ~FileHandler();
    void writeToFile(time_t sessionTime, time_t printTime, int counter);
    void setFileName(std::string name);
};

#endif /* _FILE_DECODER_H_ */
