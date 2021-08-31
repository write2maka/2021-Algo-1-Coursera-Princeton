/*
 * improvisedWeightedQuickUnion.h
 *
 *  Created on: Aug 30, 2021
 *      Author: maaya
 */

#ifndef INC_IMPROVISEDWEIGHTEDQUICKUNION_H_
#define INC_IMPROVISEDWEIGHTEDQUICKUNION_H_

class ImprovisedWeightedQuickUnion {

public:
        // Constructor
        ImprovisedWeightedQuickUnion(int N);

        // Destructor
        ~ImprovisedWeightedQuickUnion();

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


#endif /* INC_IMPROVISEDWEIGHTEDQUICKUNION_H_ */
