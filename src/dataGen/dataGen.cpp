/*
Original
########################
author: Hunter Spack
Class: CSI-280-01
Assignment: PA3 - Part 4
Date Assigned: 9/28/2020
Date Due: 10/12/2020
########################
New
########################
author: Hunter Spack
Class: CSI 230-2
Assignment: Final
Date Assigned: 12/2/2020
Date Due: 12/13/20/20
#########################
Description: generates ints and outputs them to files in random order 
Certification of Authenticity:	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
-Reproduce  this  assignment  and  provide  a  copy  to  another  member  of academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

#include "dataGen.h"

void numberGen(int size)
{
    const long long SIZE = size;
    srand(time(NULL));
    std::fstream outFile;
    outFile.open("bin/dataset.txt", std::fstream::out);
    int* randArray = NULL;
    randArray = new int[SIZE];
    for (long long i = 0; i < SIZE; i++)
    {
        int randNum = (rand() % 1000) + 1;
        outFile << randNum << std::endl;
        randArray[i] = randNum;
    }
    outFile.close();
}
