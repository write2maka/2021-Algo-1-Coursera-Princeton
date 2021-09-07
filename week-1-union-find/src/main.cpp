/*
 * main.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */
#include <iostream>
#include <time.h>

#include <quickFind-2.h>
#include <quickUnion.h>
#include <weightedQuickUnion.h>
#include <improvisedWeightedQuickUnion.h>

#include <Percolation.h>

#define INPUT_SIZE 10
#define PERCOLATION_MATRIX_SIZE 4
#define UnionFind ImprovisedWeightedQuickUnion

#define DEBUG 0

using namespace std;

void testUnionFind () {
    int inputSize = INPUT_SIZE;

    int connect[][2] = {
                            {4, 3},
                            {3, 8},
                            {6, 5},
                            {9, 4},
                            {2, 1}
                    };

    int checkConnection[][2] = {
    		{8, 9},
			{5, 4}
    };

    int moreConnects[][2] = {
                            {5, 0},
                            {7, 2},
                            {6, 1},
                            {7, 3}
                    };

    // Get the number of rows
    int connect_rowSize = sizeof(connect) / sizeof(connect[0]);
    cout << "connect number of rows = " << connect_rowSize << endl;

    // Get the number of rows
    int checkConnection_rowSize = sizeof(checkConnection) / sizeof(checkConnection[0]);
    cout << "checkConnection number of rows = " << checkConnection_rowSize << endl;

    // Get the number of rows
    int moreConnects_rowSize = sizeof(moreConnects) / sizeof(moreConnects[0]);
    cout << "connect number of rows = " << moreConnects_rowSize << endl;

    // Initialize the UnionFind class
    UnionFind data(inputSize);

    // Connect the nodes
    for (int i = 0; i < connect_rowSize; i++) {
            data.connect(connect[i][0], connect[i][1]);
    }

    // Check if nodes are connected
    for (int i = 0; i < checkConnection_rowSize; i++) {
            cout << checkConnection[i][0] << " and " << checkConnection[i][1] << " are ";
            cout << (data.fConnected(checkConnection[i][0], checkConnection[i][1]) ? "connected":"not connected") << endl;
    }

    // Connect more nodes
    cout << endl;
    for (int i = 0; i < moreConnects_rowSize; i++) {
            data.connect(moreConnects[i][0], moreConnects[i][1]);
    }

    return;
}

void testPercolation() {
	int sz = PERCOLATION_MATRIX_SIZE;

	// Initialize srand with time
	srand(time(0));

	// Instantiate the percolation object
	Percolation percolationObj(sz);

	int num;
	int row;
	int col;

	// Open sites randomly
	while (!percolationObj.percolates()) {
		// Generate random number and mod the number by the matrix size
		num = rand() % (sz * sz);
		row = num / sz;
		col = num % sz;

		if (!percolationObj.isOpen(row, col)) {
			percolationObj.open(row, col);
		}
	}

	// Print the number of open sites
	int openSites = percolationObj.numberOfOpenSites();

	cout << "Number of openSites: " << openSites;
}

//
// Main function
//
int main() {
	// Test UnionFind Algorithm
	// testUnionFind();

	testPercolation();
	return 0;
}


