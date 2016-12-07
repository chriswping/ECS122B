#include <string>
#include <utility>
#include <fstream>
#include <iostream>

using namespace std;
 
void quicksort(int* a, int lo, int hi) {
    if (hi <= lo) return;
    int size = hi - lo;

    int pindex = rand() % size + 1;
    pindex += lo;
    // v is the partitioning element
    swap(a[pindex], a[hi]);
    int v = a[hi];
    int i = lo - 1, j = hi;
    while (true) {
        // Scan left->R as much as possible
        while(a[++i] < v) ;
        // Scan right->L as much as possible
        while(v < a[--j])
            if (j == lo) break;
        if (j <= i) break;
        swap(a[i], a[j]);
    }
    // a[i] > v, place pivot element
    swap(a[i], a[hi]);
    quicksort(a, lo, i - 1);
    quicksort(a, i + 1, hi);
    return;
}



int main(int argc, char* argv[]) {
  
    ifstream infile;
    infile.open(argv[1]);
    int n = stoi(argv[2]);
    int size;
    string line = "";
    infile >> line;
    size = stoi(line);
    int* a = new int[size];
    srand(time(0));
    for(int i = 0; i < size; i++){
         infile >> line;
         a[i] = stoi(line);
    }
    quicksort(a, 0, size - 1);
  //  cout<<a[n-1]<<"\n";
    int min = a[0];
    delete[] a;
    return min;
}
