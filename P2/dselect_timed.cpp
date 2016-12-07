#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
int dselect(int* a, int lo, const int hi, const int n);

int partition5(int *a, int lo, int hi){
      int i, j, tmp;
      for (i = lo + 1; i <= hi; i++) {
           tmp = a[i];
           j = i;
           while (j > lo && a[j - 1] >= tmp) {
                  a[j] = a[j - 1];
                  j--;
           }
           a[j] = tmp;
      }
      return lo + ((hi-lo)/2);
} 
int pivot(int* a, int lo, int hi){
    if (hi - lo < 5) return lo + ((hi-lo)/2);
    int new_hi = 1;
    for (int i = lo; i < hi; i += 5){
        int sub_hi = i + 4;
        if(sub_hi > hi) sub_hi = hi;
        //cout<<i<<":"<<sub_hi<<endl;
        int median5 = partition5(a, i, sub_hi);
        //cout<<"median5:"<<a[median5]<<endl;
        int floorpos = floor((i - lo)/5);
       // cout<<"floor:"<<floorpos<<endl;
        //cout<<a[median5]<<endl;
        swap(a[median5], a[lo + floorpos]);
        new_hi++;
    }
    //cout<<"pos:"<<new_hi<<endl;
    return dselect(a, lo, lo + new_hi, lo + (hi - lo)/10);
}
int partition(int* a, int lo, int hi, int pindex){
    swap(a[pindex], a[hi]); //move pivot to the end
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


int dselect(int* a, int lo, const int hi, const int n) {
    if (hi == lo) return lo;
    int pindex = pivot(a, lo, hi);
    pindex = partition(a, lo, hi, pindex);
    if(n == pindex) return n;
    else if (n < pindex){
        return dselect(a, lo, pindex - 1, n);
    }
    else {
        return dselect(a, pindex + 1, hi, n);
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
    int kth = dselect(a, 0, size - 1, n - 1);
  //  cout<<a[kth]<<endl;
    
    int min = a[0];
    delete[] a;
    return min;
}
