#include <iostream>
#include <vector>
#include <string>                   //stoi
#include <stdlib.h>
#include <unistd.h>
#include "../headers/vectorutils.h"

bool PRINTVECTS = 0;

void makeQuicksort(const std::vector<int>& sortedVec, const std::vector<int>& unsortedVec){
    std::vector<int> vectorcopy = unsortedVec;
    /*
     * stats[0] = número de comparaciones
     * stats[1] = número de intercambios
    */
    std::vector<unsigned> stats{0,0};

    // Ordenar mediante quicksort
    std::cout << "\n* Quicksort\n";
    if (PRINTVECTS)
        printVector(vectorcopy, "Unsorted list:");

    quicksort(vectorcopy, 0, vectorcopy.size()-1, stats);
    if (PRINTVECTS)
        printVector(vectorcopy, "Sorted list  :");
    std::cout << "\tQuicksort Stats:\n" <<
        "\t\tComps: " << stats[0] << '\n' <<
        "\t\tSwaps: " << stats[1] << '\n';
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
    std::cout << "\n* Bubblesort\n";
    vectorcopy = unsortedVec;
    if (PRINTVECTS)
        printVector(vectorcopy, "\tUnsorted list:");
    bubbleSort(vectorcopy, stats, swpflag);
    if (PRINTVECTS)
        printVector(vectorcopy, "\tSorted list  :");
    std::cout << "\tBubblesort Stats:\n" <<
        "\t\tComps: " << stats[0] << '\n' <<
        "\t\tSwaps: " << stats[1] << '\n';
}

// función principal
int main(int argc, char **argv){
    
    std::vector<int> sortedVec, unsortedVec;

    int opt;
    int vecsize = 0;
    while ((opt = getopt(argc, argv, "n:p")) != EOF)
        switch (opt){
            case 'n':
                vecsize = std::stoi(optarg); break;
            case 'p':
                PRINTVECTS = true;
        }
    
    sortedVec = genSortedVec(vecsize);
    unsortedVec = genUnsortedVec(sortedVec);

    makeQuicksort(sortedVec, unsortedVec);
    
    makeBubblesort(sortedVec, unsortedVec);

    std::cout << "\n\n(SIN FLAG DE SALIDA)";
    makeBubblesort(sortedVec, unsortedVec, false);
}
