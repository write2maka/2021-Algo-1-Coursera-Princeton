/*
 * quickFind-1.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */

#include <quickFind-2.h>
#include <iostream>

using namespace std;

//
// Constructor
//
QuickFind::QuickFind(int N) {
        cout << "QuickFind initialized with N=" << N << endl;

        // Needed to print array
        arraySize = N;

        // Allocate memory for the array
        arr = new int[N];

        // Initialize the array
        for (int i = 0; i < N; i++) {
                arr[i] = i;
        }
}

//
// Destructor
//
QuickFind::~QuickFind() {
        cout << "\nQuickFind Destructor called" << endl;

        // Free the memory
        delete arr;
}

//
// Connect nodes p and q
//
void QuickFind::connect(int p, int q) {
        cout << "Connect called with " << p << " and " << q << endl;

        int pVal = arr[p];
        int qVal = arr[q];

        for(int i = 0; i < arraySize; i++) {
                if (arr[i] == pVal) {
                        arr[i] = qVal;
                }
        }

        // Print the array post connection
        printArray();
}

//
// Check if nodes p and q are connected
//
bool QuickFind::fConnected(int p, int q) {
        return (arr[p] == arr[q]);
}

//
// Helper function to print array
//
void QuickFind::printArray() {
        cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
                cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;
}
