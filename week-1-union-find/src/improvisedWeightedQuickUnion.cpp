/*
 * improvisedWeightedQuickUnion.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: write2maka
 */


#include <improvisedWeightedQuickUnion.h>
#include <iostream>

using namespace std;

//
// Constructor
//
ImprovisedWeightedQuickUnion::ImprovisedWeightedQuickUnion(int N) {
        cout << "ImprovisedWeightedQuickUnion initialized with N=" << N << endl;

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
ImprovisedWeightedQuickUnion::~ImprovisedWeightedQuickUnion() {
        cout << "\nImprovisedWeightedQuickUnion Destructor called" << endl;

        // Free the memory
        delete arr;
        delete treeSizeArr;
}

//
// Connect nodes p and q
//
void ImprovisedWeightedQuickUnion::connect(int p, int q) {
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
bool ImprovisedWeightedQuickUnion::fConnected(int p, int q) {
        return (getRoot(p) == getRoot(q));
}

int ImprovisedWeightedQuickUnion::getRoot(int num) {

	int temp = num;

	// Find root of num
	while (arr[temp] != temp) {
		temp = arr[temp];
	}

	// Update parent of num to root of num to flatten the tree
	arr[num] = temp;

	// Return root of num
	return temp;
}

//
// Helper function to print array
//
void ImprovisedWeightedQuickUnion::printArray() {
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

