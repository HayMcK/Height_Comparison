#include "SpeakerView.h"
#include "MonoStack.h"

//Default Constructor
SpeakerView::SpeakerView(std::string &fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + fileName);
    }

    // Initialize numRows and numCols to zero
    numRows = 0;
    numCols = 0;

    // Count the number of rows and columns
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        double value;
        int colCount = 0;
        while (iss >> value) {
            ++colCount;
        }
        ++numRows; // Increment the number of rows for each line
        numCols = std::max(numCols, colCount);
    }

    // Reset the file pointer to the beginning
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    // Allocate memory for seatHeights and unobstrctView
    seatHeights = new double*[numRows];
    for (int i = 0; i < numRows; ++i) {
        seatHeights[i] = new double[numCols];
    }
    unobstrctView = new int[numCols];

    // Initialize unobstrctView
    for (int i = 0; i < numCols; ++i) {
        unobstrctView[i] = 0;
    }

    // Read the seat heights from the file
    for (int i = 0; i < numRows; ++i) {
        std::getline(inputFile, line);
        std::istringstream iss(line);
        for (int j = 0; j < numCols; ++j) {
            if (!(iss >> seatHeights[i][j])) {
                throw std::runtime_error("Error: Invalid input format in file " + fileName);
            }
        }
    }

    // Close the input file
    inputFile.close();
}

//Destructor
SpeakerView::~SpeakerView() {
    // Deallocate memory for seatHeights array
    for (int i = 0; i < numRows; ++i) {
        delete[] seatHeights[i];
    }
    delete[] seatHeights;
    delete[] unobstrctView;
}

//Function for determining which seats have an unobstructed view
void SpeakerView::determineUnobstrctView() {
    for (int col = 0; col < numCols; ++col) {
        unobstrctView[col] = 1;
        MonoStack<double> decreasingStack(numRows);
        double prevHeight = -1.0; // Initialize to a negative value
        for (int row = 0; row < numRows; ++row) {
            double currentHeight = seatHeights[row][col];
            if (currentHeight >= prevHeight) {
                while (!decreasingStack.isEmpty() && decreasingStack.peek() <= currentHeight) {
                    decreasingStack.pop();
                    unobstrctView[col]++;
                }
                decreasingStack.push(currentHeight);
                prevHeight = currentHeight; // Update the previous height
            }
        }
    }
}

/*Function to display the results formatted so that
the number of seats with an unobstructed view and
their respective heights are displayed for each column.*/
void SpeakerView::displayResults() const {
    for (int col = 0; col < numCols; ++col) {
        double prevHeight = 0.0;
        std::cout << "In column " << col << " there are " << unobstrctView[col] << " that can see. Their heights are: ";
        
        // Display heights for the current column
        bool isFirstHeight = true;
        for (int row = 0; row < numRows; ++row) {
            if (seatHeights[row][col] >= prevHeight) { // Only display if height is positive and there is at least one unobstructed view
                if (!isFirstHeight) {
                    std::cout << ", ";
                }
                std::cout << seatHeights[row][col] << " inches";
                isFirstHeight = false;
            }
            prevHeight = seatHeights[row][col];
        }
        std::cout << std::endl;
    }
}

//Function to add a height into their respecitve seat position
void SpeakerView::addSeatHeight(int row, int col, double height) {
    // Ensure row and column indices are within bounds
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Error: Row or column index out of range");
    }

    // Add the height to the specified position in seatHeights
    seatHeights[row][col] = height;
}
