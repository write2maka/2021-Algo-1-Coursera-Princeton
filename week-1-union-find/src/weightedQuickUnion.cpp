/*
 * weightedQuickUnion.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */

#include <weightedQuickUnion.h>
#include <iostream>

using namespace std;

//
// Constructor
//
WeightedQuickUnion::WeightedQuickUnion(int N) {
        cout << "WeightedQuickUnion initialized with N=" << N << endl;

        // Needed to print array
        arraySize = N;

        // Allocate memory for the array
        arr = new int[N];

        // Initialize the array
        for (int i = 0; i < N; i++) {
                arr[i] = i;
        }

        // Allocate memory and initialize the treeSizeArr array
        treeSizeArr = new int[N];
        for (int i = 0; i < N; i++) {
        		// Tree of each node at start is 1
                treeSizeArr[i] = 1;
        }
}

//
// Destructor
//
WeightedQuickUnion::~WeightedQuickUnion() {
        cout << "\nWeightedQuickUnion Destructor called" << endl;

        // Free the memory
        delete arr;
        delete treeSizeArr;
}

//
// Connect nodes p and q
//
void WeightedQuickUnion::connect(int p, int q) {
        cout << "Connect called with " << p << " and " << q << endl;

        int pRoot = getRoot(arr[p]);
        int qRoot = getRoot(arr[q]);

        if (pRoot == qRoot) {
        	// The nodes are already connected
        	return;
        }

        if (treeSizeArr[pRoot] < treeSizeArr[qRoot]) {
        	// Connect root of p with root of q
        	arr[pRoot] = qRoot;

        	// Add treeSizeArr of p to that of q
        	treeSizeArr[qRoot] += treeSizeArr[pRoot];
        }
        else {
        	// Connect root of q with root of p
        	arr[qRoot] = pRoot;

        	// Add treeSizeArr of p to that of q
        	treeSizeArr[pRoot] += treeSizeArr[qRoot];
        }

        // Print the array post connection
        printArray();
}

//
// Check if nodes p and q are connected
//
bool WeightedQuickUnion::fConnected(int p, int q) {
        return (getRoot(p) == getRoot(q));
}

int WeightedQuickUnion::getRoot(int num) {
	while (arr[num] != num) {
		num = arr[num];
	}

	return num;
}

//
// Helper function to print array
//
void WeightedQuickUnion::printArray() {
        cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
                cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Children node array: ";
        for (int i = 0; i < arraySize; i++) {
                cout << treeSizeArr[i] << " ";
        }
        cout << endl;

        cout << endl;
}


