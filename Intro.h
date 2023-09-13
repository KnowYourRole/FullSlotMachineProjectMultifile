#ifndef INTRO_H
#define INTRO_H

using namespace std;

// Function to display an introduction to the game
void displayIntroduction() {
    cout << "Welcome to the Fruit Matching Game!" << endl;
    cout << "Match three or more consecutive fruits to win points." << endl;
}

// Function to get the number of rows from the player
int getNumberOfRows() {
    int numRows;
    do {
        cout << "Enter the number of rows (minimum 3, maximum 10): ";
        cin >> numRows;
    } while (numRows < 3 || numRows > 10);
    return numRows;
}


#endif