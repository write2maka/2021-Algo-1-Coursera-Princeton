/*
 * weightedQuickUnion.h
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */

#ifndef INC_WEIGHTEDQUICKUNION_H_
#define INC_WEIGHTEDQUICKUNION_H_

class WeightedQuickUnion {

public:
        // Constructor
        WeightedQuickUnion(int N);

        // Destructor
        ~WeightedQuickUnion();

        // Union
        void connect(int p, int q);

        // Find
        bool fConnected(int p, int q);

private:
        // Array holding the nodes
        int * arr;
        // Tree size of the root node
        int * treeSizeArr;

        // Size of the array
        int arraySize;

        int getRoot(int num);

        void printArray();
};

#endif /* INC_WEIGHTEDQUICKUNION_H_ */
