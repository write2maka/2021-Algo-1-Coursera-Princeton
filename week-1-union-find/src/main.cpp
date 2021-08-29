/*
 * main.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */
#include <iostream>
#include <quickFind-2.h>

#define INPUT_SIZE 10
#define UnionFind QuickFind

using namespace std;

//
// Main function
//
int main() {
        int inputSize = INPUT_SIZE;

        int connect[][2] = {
                                {4, 3},
                                {3, 8},
                                {6, 5},
                                {9, 4},
                                {2, 1},
                        };

        int checkConnection[][2] = {
        		{8, 9},
				{5, 4}
        };

        // Get the number of rows
        int connect_rowSize = sizeof(connect) / sizeof(connect[0]);
        cout << "connect number of rows = " << connect_rowSize << endl;

        // Get the number of rows
        int checkConnection_rowSize = sizeof(checkConnection) / sizeof(checkConnection[0]);
        cout << "checkConnection number of rows = " << checkConnection_rowSize << endl;

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

        return 0;
}


