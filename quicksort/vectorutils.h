/* Funciones de generación de vectores */
std::vector<int> genSortedVec(const int n);

// Funcion sobrecargada
std::vector<int> genUnsortedVec(const int n);
std::vector<int> genUnsortedVec(const std::vector<int> v1);

// Funciones sobre vectores
void printVector(const std::vector<int>& v);
void quicksort(std::vector<int>& v, int lo, int hi);
