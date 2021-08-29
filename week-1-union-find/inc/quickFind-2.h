/*
 * quickFind-1.h
 *
 *  Created on: Aug 29, 2021
 *      Author: write2maka
 */

#ifndef INC_QUICKFIND_2_H_
#define INC_QUICKFIND_2_H_

class QuickFind {

public:
        // Constructor
        QuickFind(int N);

        // Destructor
        ~QuickFind();

        // Union
        void connect(int p, int q);

        // Find
        bool fConnected(int p, int q);

private:
        int * arr;
        int arraySize;

        void printArray();
};

#endif /* INC_QUICKFIND_2_H_ */
