/*
 * quickUnion.h
 *
 *  Created on: Aug 29, 2021
 *      Author: maaya
 */

#ifndef INC_QUICKUNION_H_
#define INC_QUICKUNION_H_


class QuickUnion {

public:
        // Constructor
        QuickUnion(int N);

        // Destructor
        ~QuickUnion();

        // Union
        void connect(int p, int q);

        // Find
        bool fConnected(int p, int q);

private:
        int * arr;
        int arraySize;

        int getRoot(int num);

        void printArray();
};


#endif /* INC_QUICKUNION_H_ */
