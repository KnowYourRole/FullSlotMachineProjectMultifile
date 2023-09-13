#include <iostream>

#include "Intro.h"
#include "Info.h"
#include "LineChecks.h"
#include "Print.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    displayIntroduction();

    int numRows = getNumberOfRows();
    const int numCols = 5;  // Number of columns (can be adjusted)

    Fruit matrix[10][5];  // Assuming a maximum of 10 rows, adjust if needed

    // Fill and print the matrix
    fillAndPrintMatrix(matrix, numRows, numCols);

    // Check for wins on each row
    int totalWon = 0;
    for (int curRow = 0; curRow < numRows; curRow++) {
        totalWon += checkLine(matrix, numRows, numCols, curRow);
    }

    totalWon += checkLineVStyle(matrix, numRows, numCols, 0);
    totalWon += checkLineVStyle(matrix, numRows, numCols, numRows - 1);
    totalWon += checkLineWStyle(matrix, numRows, numCols);

    if (totalWon == 0) {
        cout << "Better luck next time!" << endl;
    } else {
        cout << "Total Won: " << totalWon << "p" << endl;
    }

    return 0;
}
