#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Enum representing fruit symbols
enum class Fruit { CHERRY, ORANGE, LEMON, PLUM, WATERMELON, GRAPE };

// Function to convert a Fruit enum to its corresponding character
char fruitToChar(Fruit fruit) {
    switch (fruit) {
        case Fruit::CHERRY: return 'C';
        case Fruit::ORANGE: return 'O';
        case Fruit::LEMON: return 'L';
        case Fruit::PLUM: return 'P';
        case Fruit::WATERMELON: return 'W';
        case Fruit::GRAPE: return 'G';
        default: return '?';
    }
}

// Function to generate a random fruit
Fruit getRandomFruit() {
    int random = rand() % 6;
    return static_cast<Fruit>(random);
}

// Function to get points for a specific fruit and number of consecutive fruits
int getPoints(Fruit fruit, int consecutiveCount) {
    switch (fruit) {
        case Fruit::CHERRY:
            return (consecutiveCount == 1) ? 0 : (consecutiveCount == 2) ? 5 : (consecutiveCount == 3) ? 10 : (consecutiveCount == 4) ? 20 : 30;
        case Fruit::ORANGE:
            return (consecutiveCount == 1) ? 0 : (consecutiveCount == 2) ? 35 : (consecutiveCount == 3) ? 40 : (consecutiveCount == 4) ? 50 : 60;
        case Fruit::LEMON:
            return (consecutiveCount == 3) ? 70 : (consecutiveCount == 4) ? 80 : 90;
        case Fruit::PLUM:
            return (consecutiveCount == 3) ? 100 : (consecutiveCount == 4) ? 110 : 120;
        case Fruit::WATERMELON:
            return (consecutiveCount == 3) ? 130 : (consecutiveCount == 4) ? 140 : 150;
        case Fruit::GRAPE:
            return (consecutiveCount == 4) ? 170 : 180;
        default:
            return 0;
    }
}

#endif