#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int partition(int* a, int lo, int hi, int pindex){
    swap(a[pindex], a[hi]);
    int pvalue = a[hi];
    int currentindex = lo;
    for(int i = lo; i < hi; i++){
        if(a[i] < pvalue) {
            swap(a[currentindex], a[i]);
            currentindex++;
        }
    }
    // a[i] < v, place pivot element
    swap(a[hi], a[currentindex]);
    return currentindex;
}


int quickselect(int* a, int lo, const int hi, const int n) {
    if (hi == lo) return a[lo];
    int size = hi - lo;
    int pindex = rand() % size + 1;
    pindex += lo;
    pindex = partition(a, lo, hi, pindex);
    if(n == pindex) return a[n];
    else if (n < pindex){
        return quickselect(a, lo, pindex - 1, n);
    }
    else {
        return quickselect(a, pindex + 1, hi, n);
    }
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
    int kth = quickselect(a, 0, size - 1, n - 1);
    //cout<<kth<<endl;
    
    int min = a[0];
    delete[] a;
    return min;
}
