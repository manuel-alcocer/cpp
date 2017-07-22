#include <iostream>
#include <vector>
#include <string>                   //stoi
#include <stdlib.h>
#include <unistd.h>
#include "../headers/timer.h"
#include "../headers/vectorutils.h"

bool PRINTVECTS = 0;

void makeQuicksort(const std::vector<int>& sortedVec,
        const std::vector<int>& unsortedVec){
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
    std::cout.imbue(std::locale(""));
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
    std::cout.imbue(std::locale(""));
    std::cout << "\tBubblesort Stats:\n" <<
        "\t\tComps: " << stats[0] << '\n' <<
        "\t\tSwaps: " << stats[1] << '\n';
}

// función principal
int main(int argc, char **argv){

    std::vector<int> sortedVec, unsortedVec;
    double clock_init, clock_stop;

    int opt;
    int vecsize = 0;
    while ((opt = getopt(argc, argv, "n:p")) != EOF)
        switch (opt){
            case 'n':
                vecsize = std::stoi(optarg); break;
            case 'p':
                PRINTVECTS = true;
        }

    std::cout << "Generating list....\n";
    start_timer(clock_init);
    sortedVec = genSortedVec(vecsize);
    unsortedVec = genUnsortedVec(sortedVec);
    stop_timer(clock_stop);
    printTime(clock_init, clock_stop);

    start_timer(clock_init);
    makeQuicksort(sortedVec, unsortedVec);
    stop_timer(clock_stop);
    printTime(clock_init, clock_stop);

    start_timer(clock_init);
    makeBubblesort(sortedVec, unsortedVec);
    stop_timer(clock_stop);
    printTime(clock_init, clock_stop);

    start_timer(clock_init);
    std::cout << "\n\n(SIN FLAG DE SALIDA)";
    makeBubblesort(sortedVec, unsortedVec, false);
    stop_timer(clock_stop);
    printTime(clock_init, clock_stop);
}
