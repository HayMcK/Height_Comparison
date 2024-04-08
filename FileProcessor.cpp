#include "FileProcessor.h"


//Default constructor
FileProcessor::FileProcessor(){
}

//Destructor
FileProcessor::~FileProcessor(){}

/* A function to process the input file and call the  SpeakerView 
class to interpret the input data, then output the seats 
with an unobstructed view. */
void FileProcessor::processFile(std::string inpFile){
    if(!checkTXT(inpFile)){ //check if the file ends with .txt
        std::cout << "Invalid input file name. Must be a .txt file." << std::endl;
    }
    else{
        std::ifstream inputFile(inpFile);
        if (inputFile.fail()) {
            throw std::runtime_error("Error: Unable to open file " + inpFile);
        }
        // Create a SpeakerView object to process the file
        SpeakerView speakerView(inpFile);

        std::string line;
        int row = 0;
        int col = 0;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            col = 0;
            double height;
            while (ss >> height) {
                speakerView.addSeatHeight(row, col++, height);
            }
            ++row;
        }

        // Close the input file
        inputFile.close();
        // Determine unobstructed views and display results
        speakerView.determineUnobstrctView();
        speakerView.displayResults();

    
    }
}

/* A boolean function to check if the input file name
that is input in the command line is a .txt file. */
bool FileProcessor::checkTXT(std::string fileName){
    std::string end = ".txt";
    std::string tmp;
    if(fileName.length() <= 4){//make sure the file name isn't just ".txt" or shorter
        return 0;
    }
    for (int i = fileName.length()-4; i < fileName.length(); ++i){//only compare the end of the string for the filename extension type of txt
        tmp = tmp + fileName[i];
    }
    if(tmp == end){
        return 1;
    }
    else{return 0;}
}