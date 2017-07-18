#include <vector>
#include <algorithm>

void quicksort(std::vector<int>& v, int lo, int hi);

void doCycle(std::vector<int>& v, int lo, int hi){
    int i = lo, p = hi, j = hi - 1;
    while ( i < j && p - i > 0 ) {
        if ( v[i] > v[p] && v[j] < v[p] ) {
            std::swap(v[i],v[j]);
            i++;
            j--;
        }
        else {
            if ( v[i] < v[p] ) i++;
            if ( v[j] > v[p] ) j--;
        }
    }
    while ( v[i] < v[p] ) i++;
    std::swap(v[i],v[p]);
    quicksort(v, lo, i - 1);
    quicksort(v, i + 1, hi);
}

void quicksort(std::vector<int>& v, int lo, int hi){
    if ( hi - lo > 0 ) {
        doCycle(v, lo, hi);
    }
}
