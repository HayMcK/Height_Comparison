#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "SpeakerView.h"

/* A class that will take text files (.txt) */
class FileProcessor{
    private:
    public:
        FileProcessor();
        ~FileProcessor();
        bool checkTXT(std::string fileName);
        void processFile(std::string inpFile);
};

#endif