#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include "quicksort.h"

// Generar lista con 'n' números ordenados
void genSortedVec(std::vector<int>& v, const int n){
    for (int x = 1; x <= n; x++)
        v.push_back(x);
}

// genera un vector desordenado
void genUnsortedVec(std::vector<int> v1, std::vector<int>& v2){
    int randValue;
    srand(static_cast<unsigned>(time(0)));

    while (v1.size() > 0){
        randValue = rand() % v1.size();
        v2.push_back(v1.at(randValue));
        v1.erase(v1.begin() + randValue);
    }
}

// pide el tamaño del vector
void askVectorSize(int& v){
    std::cout << "\nList size? ";
    std::cin >> v;
}

// imprime el vector
void printVector(const std::vector<int>& v){
    std::string numstr = std::to_string(v.size());
    unsigned int strsize = numstr.size();
    for (int x : v) {
        std::cout << std::setw(strsize + 2) << x;
    }
    std::cout << '\n';
}

// función principal
int main(int argc, char *argv[]){
    std::vector<int> sortedVec, unsortedVec, copia;
    int vecsize = 0;
    
    if ( argc < 2){
        askVectorSize(vecsize);
    } else {
        vecsize = std::stoi(argv[1]);
    }

    genSortedVec(sortedVec, vecsize);

    std::cout << "\nVector ordenado: ";
    printVector(sortedVec);

    genUnsortedVec(sortedVec, unsortedVec);

    std::cout << "\nVector desordenado: ";
    printVector(unsortedVec);
    copia = unsortedVec;
    std::cout << "\nVector desordenado (copia): ";
    printVector(copia);
    int size = unsortedVec.size() - 1;
    int begin = 0;
    quicksort(unsortedVec, begin, size);

    std::cout << "\nVector después de la ordeanción: ";
    printVector(unsortedVec);

    std::cout << "\nVector desordenado (copia): ";
    printVector(copia);
}

