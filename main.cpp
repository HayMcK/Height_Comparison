#include "FileProcessor.h"

int main(int argc, char **argv){
    if(argc != 2){
        std::cerr << "Error: Invalid number of command line inputs, make sure to add an input file name." <<std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    FileProcessor process;
    process.processFile(fileName);
    return 0;

}