/*
 * Percolation.cpp
 *
 *  Created on: Sep 4, 2021
 *      Author: maaya
 */

// creates n-by-n grid, with all sites initially blocked
#include <Percolation.h>
#include <iostream>

using namespace std;

#define CLOSED 0
#define OPEN 1

Percolation::Percolation(int n) : matrix(n, vector<int>(n)), unionFind(n*n) {
	// Size of input matrix
	N = n;

	cout << "Percolation matrix size: " << N << endl;

	// Initialize count of open cells
	nOpen = 0;

	// Use this variable as a helper variable
	bPercolates = false;

	this->printMatrix();
}

// opens the site (row, col) if it is not open already
void Percolation::open(int row, int col) {
	nOpen++;

	// Return if the site is already open
	if (this->isOpen(row, col)) {
		cout << "Site (" << row << " ," << col << ") is already open" << endl;
		return;
	}

	// Open the site
	matrix[row][col] = OPEN;
	cout << "Opened site (" << row << ", " << col << ")" << endl;

	// Connect the node with its open neighbor nodes
	this->connectOpenNodes(row, col);

	// Print the matrix
	this->printMatrix();

	return;
}

// is the site (row, col) open?
bool Percolation::isOpen(int row, int col) {
	return matrix[row][col] ? true : false;
}

// is the site (row, col) full?
bool Percolation::isFull(int row, int col) {
	return false;
}

// returns the number of open sites
int Percolation::numberOfOpenSites() {
	return nOpen;
}

// does the system percolate?
bool Percolation::percolates() {
	// cout << "Percolates: " << nOpen << " vs " << (N * N * 3 /4) << " = ";

	// Check if any element in first row is connected to any element in the last row
	for (int i = 0; i < N; i++) {
		for (int j = (N - 1) * N; j < (N * N); j++) {
			if(unionFind.fConnected(i, j)) {
				cout << "Percolates: " << i << " and " << j << " are connected" << endl;
				return true;
			}
		}
	}

#if 0
	// Stop processing when number of open sites > 3/4th of matrix
	if (nOpen > (N * N * 3 / 4)) {
		cout << "true" << endl;
		return true;
	}
#endif

	cout << "Percolates: false" << endl;
	return false;
}

void Percolation::connectOpenNodes(int row, int col) {

	// Get the node index
	int p = (row * N) + col;
	int q;

	// Left node
	if (col > 0) {
		if (this->isOpen(row, (col - 1))) {
			q = p - 1;
			unionFind.connect(p, q);
		}
	}

	// Right node
	if (col < (N - 1)) {
		if (this->isOpen(row, (col + 1))) {
			q = p + 1;
			unionFind.connect(p, q);
		}
	}

	// Upper node
	if (row > 0) {
		if (this->isOpen((row - 1), col)) {
			q = ((row - 1) * N) + col;
			unionFind.connect(p, q);
		}
	}

	// Lower node
	if (row < (N - 1)) {
		if (this->isOpen((row + 1), col)) {
			q = ((row + 1) * N) + col;
			unionFind.connect(p, q);
		}
	}
}

void Percolation::printMatrix() {

	cout << "MATRIX" << endl;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}
