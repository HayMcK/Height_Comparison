#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <fstream>
#include <sstream>
#include "MonoStack.h"

class SpeakerView {
    private:
        double** seatHeights;
        double** unobstrctHeights;
        int numRows;
        int numCols;
        int* unobstrctView;
    public:
        SpeakerView(std::string &fileName);
        ~SpeakerView();
        void determineUnobstrctView();
        void displayResults() const;
        void addSeatHeight(int row, int col, double height);
};

#endif