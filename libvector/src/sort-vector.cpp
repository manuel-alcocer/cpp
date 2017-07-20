#include <iostream>
#include <vector>
#include <string>                   //stoi
#include "../headers/vectorutils.h"

// pide el tamaño del vector
void askVectorSize(int& v){
    std::cout << "\nList size?: ";
    std::cin >> v;
}

// función principal
int main(int argc, char *argv[]){
    
    std::vector<int> sortedVec, unsortedVec;
    
    /*
     * stats[0] = número de comparaciones
     * stats[1] = número de intercambios
    */
    std::vector<unsigned> stats{0,0};

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
    quicksort(vectorcopy, 0, vecsize-1, stats);
    printVector(vectorcopy, "Sorted list  :");
    std::cout << "\nQuicksort Stats:\n\n" <<
        "Comps: " << stats[0] << '\n' <<
        "Swaps: " << stats[1] << '\n';

    zerofill(stats);

    // Ordenar mediante burbuja
    std::cout << "\n\nBubblesort\n\n";
    vectorcopy = unsortedVec;
    printVector(vectorcopy, "Unsorted list:");
    bubbleSort(vectorcopy, stats);
    printVector(vectorcopy, "Sorted list  :");
    std::cout << "\nBubblesort Stats:\n\n" <<
        "Comps: " << stats[0] << '\n' <<
        "Swaps: " << stats[1] << '\n';

}
