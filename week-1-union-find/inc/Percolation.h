/*
 * Percolation.h
 *
 *  Created on: Sep 4, 2021
 *      Author: maaya
 */

#ifndef INC_PERCOLATION_H_
#define INC_PERCOLATION_H_

#include <improvisedWeightedQuickUnion.h>
#include <vector>

using namespace std;

class Percolation {
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n);

    // opens the site (row, col) if it is not open already
    void open(int row, int col);

    // is the site (row, col) open?
    bool isOpen(int row, int col);

    // is the site (row, col) full?
    bool isFull(int row, int col);

    // returns the number of open sites
    int numberOfOpenSites();

    // does the system percolate?
    bool percolates();

private:
    // Size of the matrix sz x sz
    int N;

    // Holds state of the node - empty vs full
    vector<vector <int>> matrix;

    // Holds the state of node connectivity
    ImprovisedWeightedQuickUnion unionFind;

    // Count of open sites
    int nOpen;

    // Store percolation status
    bool bPercolates;

    // Connect neighboring open nodes
    void connectOpenNodes(int row, int col);

    // Print the matrix
    void printMatrix();
};

#endif /* INC_PERCOLATION_H_ */
