#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

	int  mergeSort(int [], int, int);
        int  merge(int [], int, int, int, int);


int main(int argc, char *argv[]){

	std::ifstream is(argv[1]);
	std::istream_iterator<int> start(is), end;
	std::vector<int> numbers(start, end);
                
                int n = numbers.size();
                int A[n];
                for(int i = 0; i < n; i++)
                {
                    A[i] = numbers[i];
                }

		mergeSort(A, 0, n - 1);
//		printf("%d", n - 1);
                for(int i = 0; i < n; i++)
                        printf("%d\n", A[i]);
//                printf("\n");


/*
    int[] result;

    data = new int[1000];

    Random rand = new Random();
    for (int i = 0; i < data.length; ++i){
      data[i] = rand.nextInt(1000);
    }

    result = mergeSort(data, 0, data.length - 1);

    for (int n : result){
      System.out.print(n + " ");
    }
    System.out.println();
*/
    return 0;
  }

  int mergeSort (int A[], int p, int s){
    int q, r;
    int b1, e1, b2, e2, b3, e3;

    if (p < s){

      q = (s - p) / 3;
      r = 2 * q;

      b1 = p;           
      e1 = p + q;       
      b2 = e1 + 1;      
      e2 = p + r;       
      b3 = e2 + 1;      
      e3 = s;           


      mergeSort(A, b1, e1);
      mergeSort(A, b2, e2);
      mergeSort(A, b3, e3);


      merge(A, b1, e1, e2, e3);
    }
  }

  int merge (int A[], int p, int q, int r, int s){
    int h, i, j, k;

    int sublen1 = q - p + 1;     
    int sublen2 = r - q;        
    int sublen3 = s - r;    

    int* seq1 = new int[sublen1];
    //int seq1length = sizeof(seq1) / sizeof( seq1[0] );
    for (int n = 0; n < sublen1; ++n){
      seq1[n] = A[p + n];
    }
    int* seq2 = new int[sublen2];
    //int seq2length = sizeof(seq2) / sizeof( seq2[0] );        
    for (int n = 0; n < sublen2; ++n){
      seq2[n] = A[q + n + 1];
    }
    int* seq3 = new int[sublen3];
    //int seq3length = sizeof(seq3) / sizeof( seq3[0] );
    for (int n = 0; n < sublen3; ++n){
      seq3[n] = A[r + n + 1];
    }


    h = 0; i = 0; j = 0; 
    k = p;

    while (h < sublen1 && i < sublen2 && j < sublen3){
      if (seq1[h] <= seq2[i] && seq1[h] <= seq3[j]){
        A[k++] = seq1[h++];
      }
      else if (seq2[i] <= seq1[h] && seq2[i] <= seq3[j]){
        A[k++] = seq2[i++];
      }
      else if (seq3[j] <= seq1[h] && seq3[j] <= seq2[i]){

A[k++] = seq3[j++];

}

}



while (h < sublen1 && i < sublen2){

if (seq1[h] <= seq2[i]){

A[k++] = seq1[h++];

}

else{

A[k++] = seq2[i++];

}

}

while (h < sublen1 && j < sublen3){

if (seq1[h] <= seq3[j]){

A[k++] = seq1[h++];

}

else{

A[k++] = seq3[j++];

}

}

while (i < sublen2 && j < sublen3){

if (seq2[i] <= seq3[j]){

A[k++] = seq2[i++];

}

else{

A[k++] = seq3[j++];

}

}





while (h < sublen1){

A[k++] = seq1[h++];

}

while (i < sublen2){

A[k++] = seq2[i++];

}

while (j < sublen3){

A[k++] = seq3[j++];

}



}


