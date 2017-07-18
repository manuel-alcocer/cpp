#include <iostream>
#include <vector>
#include <algorithm>            // swap
#include <cstdlib>              // rand, srand
#include <ctime>
#include <iomanip>              // setw
#include "vectorutils.h"

// Generar lista con 'n' números ordenados
std::vector<int> genSortedVec(const int n){
    std::vector<int> v;
    for (int x = 1; x < n + 1; x++)
        v.push_back(x);
    return v;
}

// genera un vector desordenado dado otro
std::vector<int> genUnsortedVec(std::vector<int> v1){
    int randValue;
    std::vector<int> v2;
    srand(static_cast<unsigned>(time(0)));

    while (v1.size() > 0){
        randValue = rand() % v1.size();
        v2.push_back(v1.at(randValue));
        v1.erase(v1.begin() + randValue);
    }
    return v2;
}

// genera un vector desordenado de n elementos
std::vector<int> genUnsortedVec(const int n){
    std::vector<int> v2 = genUnsortedVec(genSortedVec(n));
    return v2;
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

int doCycle(std::vector<int>& v, int lo, int hi){
    int i = lo, p = hi, j = hi - 1;
    while ( i < j && p - i > 0 ) {
        if ( v[i] > v[p] && v[j] < v[p] ) {
            std::swap(v[i],v[j]);
            i++;
            j--;
        }
        else {
            if (v[i] < v[p]) i++;
            if (v[j] > v[p]) j--;
        }
    }
    while (v[i] < v[p]) i++;
    std::swap(v[i],v[p]);
    return i;
}

void quicksort(std::vector<int>& v, int lo, int hi){
    int p;
    if (hi - lo > 0) {
        p = doCycle(v, lo, hi);
        quicksort(v, lo, p - 1);
        quicksort(v, p + 1, hi);
    }
}
