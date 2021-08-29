/*
 * quickFind-1.cpp
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */

#if 0

#include <iostream>

using namespace std;

class UnionFind {

public:
        // Constructor
        UnionFind(int N);

        // Destructor
        ~UnionFind();

        // Union
        void connect(int p, int q);

        // Find
        bool fConnected(int p, int q);

private:
        int * arr;
        int arraySize;

        void printArray();
};

//
// Constructor
//
UnionFind::UnionFind(int N) {
        cout << "UnionFind initialized with N=" << N << endl;

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
UnionFind::~UnionFind() {
        cout << "UnionFind Destructor called" << endl;

        // Free the memory
        delete arr;
}

//
// Connect nodes p and q
//
void UnionFind::connect(int p, int q) {
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
bool UnionFind::fConnected(int p, int q) {
        return (arr[p] == arr[q]);
}

//
// Helper function to print array
//
void UnionFind::printArray() {
        cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
                cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;
}

//
// Main function
//
int main() {
        int inputSize = 10;
        int connect_1[][2] = {
                                {4, 3},
                                {3, 8},
                                {6, 5},
                                {9, 4},
                                {2, 1},
                        };

        // Get the number of rows
        int connect_1_rowSize = sizeof(connect_1) / sizeof(connect_1[0]);
        cout << "connect_1 number of rows = " << connect_1_rowSize << endl;

        // Initialize the UnionFind class
        UnionFind data(inputSize);

        // Connect the nodes
        for (int i = 0; i < connect_1_rowSize; i++) {
                data.connect(connect_1[i][0], connect_1[i][1]);
        }

        // Check if nodes are connected
        cout << "8 and 9 are " << (data.fConnected(8, 9) ? "connected":"not connected") << endl;
        cout << "8 and 4 are " << (data.fConnected(8, 4) ? "connected":"not connected") << endl;

        return 0;
}

#endif
