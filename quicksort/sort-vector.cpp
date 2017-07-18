#include <iostream>
#include <vector>
#include <string>                   //stoi
#include "vectorutils.h"

// pide el tamaño del vector
void askVectorSize(int& v){
    std::cout << "\nList size?: ";
    std::cin >> v;
}

// función principal
int main(int argc, char *argv[]){
    std::vector<int> sortedVec, unsortedVec;
    int vecsize = 0;
    
    if ( argc < 2){
        askVectorSize(vecsize);
    } else {
        vecsize = std::stoi(argv[1]);
    }

    sortedVec = genSortedVec(vecsize);

    std::cout << "\nSorted list: ";
    printVector(sortedVec);

    unsortedVec = genUnsortedVec(sortedVec);
    std::cout << "\nUnsorted list: ";
    printVector(unsortedVec);

    quicksort(unsortedVec, 0, vecsize-1);
    std::cout << "\nList after sorting: ";
    printVector(unsortedVec);
}

