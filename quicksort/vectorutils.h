/* Funciones de generación de vectores */
std::vector<int> genSortedVec(const int n);

// Función sobrecargada
std::vector<int> genUnsortedVec(const int n);
std::vector<int> genUnsortedVec(const std::vector<int> v1);

/* Funciones sobre vectores */

// Función sobrecargada
void printVector(const std::vector<int>& v);
void printVector(const std::vector<int>& v, std::string msg);

void quicksort(std::vector<int>& v, int lo, int hi);
void bubbleSort(std::vector<int>& v);
