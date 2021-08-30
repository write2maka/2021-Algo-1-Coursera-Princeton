/*
 * quickUnion.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: write2maka
 */

#include <quickUnion.h>
#include <iostream>

using namespace std;

//
// Constructor
//
QuickUnion::QuickUnion(int N) {
        cout << "QuickUnion initialized with N=" << N << endl;

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
QuickUnion::~QuickUnion() {
        cout << "\nQuickUnion Destructor called" << endl;

        // Free the memory
        delete arr;
}

//
// Connect nodes p and q
//
void QuickUnion::connect(int p, int q) {
        cout << "Connect called with " << p << " and " << q << endl;

        int pRoot = getRoot(arr[p]);
        int qRoot = getRoot(arr[q]);

        // Connect root of p with root of q
        arr[pRoot] = qRoot;

        // Print the array post connection
        printArray();
}

//
// Check if nodes p and q are connected
//
bool QuickUnion::fConnected(int p, int q) {
        return (getRoot(p) == getRoot(q));
}

int QuickUnion::getRoot(int num) {
	while (arr[num] != num) {
		num = arr[num];
	}

	return num;
}

//
// Helper function to print array
//
void QuickUnion::printArray() {
        cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
                cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;
}
