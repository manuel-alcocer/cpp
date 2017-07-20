#include <iostream>
#include <vector>
#include <string>                   //stoi
#include "../headers/vectorutils.h"

// pide el tamaño del vector
void askVectorSize(int& v){
    std::cout << "\nList size?: ";
    std::cin >> v;
}

void makeQuicksort(const std::vector<int>& sortedVec, const std::vector<int>& unsortedVec){
    std::vector<int> vectorcopy = unsortedVec;
    /*
     * stats[0] = número de comparaciones
     * stats[1] = número de intercambios
    */
    std::vector<unsigned> stats{0,0};

    // Ordenar mediante quicksort
    std::cout << "\nQuicksort\n\n";
    printVector(vectorcopy, "Unsorted list:");

    quicksort(vectorcopy, 0, vectorcopy.size()-1, stats);
    printVector(vectorcopy, "Sorted list  :");
    std::cout << "\nQuicksort Stats:\n\n" <<
        "Comps: " << stats[0] << '\n' <<
        "Swaps: " << stats[1] << '\n';
}

void makeBubblesort(const std::vector<int>& sortedVec,
                    const std::vector<int>& unsortedVec,
                    bool swpflag = true){
    std::vector<int> vectorcopy = unsortedVec;
    /*
     * stats[0] = número de comparaciones
     * stats[1] = número de intercambios
    */
    std::vector<unsigned> stats{0,0};

    // Ordenar mediante burbuja con flag de salida (default = true)
    std::cout << "\n\nBubblesort\n\n";
    vectorcopy = unsortedVec;
    printVector(vectorcopy, "Unsorted list:");
    bubbleSort(vectorcopy, stats, swpflag);
    printVector(vectorcopy, "Sorted list  :");
    std::cout << "\nBubblesort Stats:\n\n" <<
        "Comps: " << stats[0] << '\n' <<
        "Swaps: " << stats[1] << '\n';
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

    makeQuicksort(sortedVec, unsortedVec);
    
    makeBubblesort(sortedVec, unsortedVec);

    std::cout << "\n\n(SIN FLAG DE SALIDA)";
    makeBubblesort(sortedVec, unsortedVec, false);
}
