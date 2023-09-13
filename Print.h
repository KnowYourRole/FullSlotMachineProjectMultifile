#ifndef PRINT_H
#define PRINT_H

// Function to fill the matrix with random fruits and print it
void fillAndPrintMatrix(Fruit matrix[][5], int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = getRandomFruit();
            cout << fruitToChar(matrix[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif