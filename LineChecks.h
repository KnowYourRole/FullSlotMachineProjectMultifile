#ifndef LINECHECKS_H
#define LINECHECKS_H

#include "Info.h"

// Function to check for wins on a single line
int checkLine(Fruit matrix[][5], int numRows, int numCols, int curRow) {
    Fruit currentFruit = matrix[curRow][0];
    Fruit winningFruit;
    int consecutiveCount = 1;
    int maxConsecutiveCount = 1;
    int totalPoints = 0;

    int lineNum;
    if(curRow == 0)
    {
        lineNum = 2;
    }
    else if(curRow == 1)
    {
        lineNum = 1;
    }
    else
    {
        lineNum = 3;
    }

    for (int j = 1; j < numCols; j++) {
        if (matrix[curRow][j] == currentFruit) {
            consecutiveCount++;
            if (consecutiveCount > maxConsecutiveCount) {
                maxConsecutiveCount = consecutiveCount;
                winningFruit = currentFruit;
            }
        } else {
            currentFruit = matrix[curRow][j];
            consecutiveCount = 1;
        }
    }

    if (maxConsecutiveCount >= 3) {
        int winPoints = getPoints(winningFruit, maxConsecutiveCount);
        totalPoints += winPoints;
        cout << "Line " << lineNum << ":" << endl;
        cout << "Figure: " << fruitToChar(winningFruit) << endl;
        cout << "Win: " << winPoints << "p" << endl;
        cout << "Figures: " << maxConsecutiveCount << endl << endl;
    }

    return totalPoints;
}

// Function to check for wins on a V line
int checkLineVStyle(Fruit matrix[][5], int numRows, int numCols, int startRow) {
    bool isDiag4;
    int totalPoints = 0;
    Fruit winningFruit;
    Fruit currentFruit = matrix[startRow][0];
    int consecutiveCount = 1;
    int maxConsecutiveCount = 1;
    
    bool goDown = (startRow == 0);  // Start from the top or bottom based on startRow

    // Skip the first fruit if startRow is strictly less than the boundary
    if (startRow == 0) {
        startRow++;
        isDiag4 = true;
    }
    else {
        startRow--;
        isDiag4 = false;
    }

    int startCol = 1;  // Always start from the second column

    while (startRow < numRows && startCol < numCols) {
        if (matrix[startRow][startCol] == currentFruit) {
            consecutiveCount++;
            if (consecutiveCount > maxConsecutiveCount) {
                maxConsecutiveCount = consecutiveCount;
                winningFruit = currentFruit;
            }
        } else {
            currentFruit = matrix[startRow][startCol];
            consecutiveCount = 1;
        }

        if (goDown) {
            startRow++;
            if (startRow == numRows) {
                goDown = false;
                startRow = numRows - 2;
            }
        } else {
            startRow--;
            if (startRow < 0) {
                goDown = true;
                startRow = 1;
            }
        }

        startCol++;  // Move to the next column
    }

    if (maxConsecutiveCount >= 3) {
        int winPoints = getPoints(winningFruit, maxConsecutiveCount);
        totalPoints += winPoints;
        cout << "Diagonal " << (isDiag4 == true ? 4 : 5) << ":" << endl;
        cout << "Figure: " << fruitToChar(winningFruit) << endl;
        cout << "Win: " << winPoints << "p" << endl;
        cout << "Figures: " << maxConsecutiveCount << endl << endl;
    }

    return totalPoints;
}

int checkLineWStyle(Fruit matrix[][5], int numRows, int numCols) {
    int totalPoints = 0;    
    int consecutiveCount = 1;
    int maxConsecutiveCount = 1;    
    bool goDown = true;  // Start from the top or bottom based on startRow
    
    int startRow = numRows - 2;
    Fruit currentFruit = matrix[startRow][0];
    Fruit winningFruit;
    int startCol = 1;  // Always start from the second column
    startRow++;

    while (startRow < numRows && startCol < numCols) {
        if (matrix[startRow][startCol] == currentFruit) {
            consecutiveCount++;
            if (consecutiveCount > maxConsecutiveCount) {
                maxConsecutiveCount = consecutiveCount;
                winningFruit = currentFruit;
            }
        } else {
            currentFruit = matrix[startRow][startCol];
            consecutiveCount = 1;
        }

        if (goDown) {
            startRow--;            
            goDown = false;
        } 
        else 
        {
            startRow++;
            goDown = true;
        }

        startCol++;  // Move to the next column
    }

    if (maxConsecutiveCount >= 3) {
        int winPoints = getPoints(winningFruit, maxConsecutiveCount);
        totalPoints += winPoints;
        cout << "Diagonal " << 6 << ":" << endl;
        cout << "Figure: " << fruitToChar(winningFruit) << endl;
        cout << "Win: " << winPoints << "p" << endl;
        cout << "Figures: " << maxConsecutiveCount << endl << endl;
    }

    return totalPoints;
}

#endif