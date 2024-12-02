/* Name: Bria Weisblat
Date: 10/24/2022
Section: 4
Assignment: Homework 4 Number Flipping
Due Date: 10/24/2022
About this project: When a user inputs a number, this program will calculate the
difference between the number and its reverse, and subtract from that a random
number at most as large as the original number.
Assumptions: Assume that the user will only enter the proper type of data.

All work below was performed by Bria Weisblat */


#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Function Calls
double reverseDiff(int userNum);
double calcVal(int userNum);

// Main Function

int main() {

    int seed;
    int userNum;
    int difference;

    cout<< "Enter the seed of the RNG: " << endl;
    cin>> seed;
    cout << "Enter a number: " << endl;
    cin>> userNum;
    cout << "The required value is: ";
    srand(seed);

    // Calls the calcVal function to print the required value
    double totalSum = 0;
    int totalNums = 0;
    while (userNum != 0) {
        int calculated = calcVal(userNum);
        cout << endl << calculated << endl;
        // Keeps track of how many numbers are entered
        totalNums +=1;
        // Keeps track of the sum of all the numbers that are entered
        totalSum += calculated;
        cout << endl << "Enter a number: " << endl;
        cin>> userNum;
        if (userNum != 0) {
            cout << "The required value is: ";
        }
    }
    //Calculates the average
    double average = totalSum / totalNums;
    cout << "The average is: " << average;


    return 0;
}

// Function Definitions

// Returns the difference between the number and its reverse
double reverseDiff(int userNum) {
    int lastDigit;
    int reverse = 0;
    int difference = 0;

    //Reverses the number
    int newNumber = userNum;
    while (newNumber > 0 ) {
        lastDigit = newNumber % 10;
        reverse = (reverse * 10) + lastDigit;
        newNumber = newNumber / 10;
    }
    // Calculates the difference
    difference = userNum - reverse;

    // Ensures that the difference is positive
    if (difference < 0) {
        difference = difference * -1;
    }
    return difference;
}

// Calculates the required value
double calcVal( int userNum) {
    double requiredVal;
        // Generates a random number
        int random = (rand() % userNum);
        // Calls the reverse diff function
        int difference = reverseDiff(userNum);
        // Subtracts the random number from the difference (determined by the reverseDiff function)
        requiredVal = difference - random;
        // Ensures that the required value is positive
        if (requiredVal < 0) {
            requiredVal = requiredVal * -1;
        }
    return requiredVal;
}


