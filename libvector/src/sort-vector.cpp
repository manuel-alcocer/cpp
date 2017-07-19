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
    unsortedVec = genUnsortedVec(sortedVec);

    // Ordenar mediante quicksort
    std::cout << "\nQuicksort\n\n";
    std::vector<int> vectorcopy = unsortedVec;
    printVector(vectorcopy, "Unsorted list:");
    quicksort(vectorcopy, 0, vecsize-1);
    printVector(vectorcopy, "Sorted list  :");

    // Ordenar mediante burbuja
    std::cout << "\n\nBubblesort\n\n";
    vectorcopy = unsortedVec;
    printVector(vectorcopy, "Unsorted list:");
    bubbleSort(vectorcopy);
    printVector(vectorcopy, "Sorted list  :");
}
