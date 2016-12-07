#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
int PARTITION(int [],int ,int, int [] );
void R_QUICKSORT(int [],int ,int, int, int, int [] );
int R_PARTITION(int [],int,int, int []);
void isort(int [],int [], int, int, int);
void insertionSort(int[], int, int, int[]);
int main(int argc, char *argv[])
{	
	int stats[3];
	for(int i = 0; i < 3; i++)
		stats[i] = 0;
	if(argc == 3)
	{
		std::ifstream is(argv[1]);
		std::istream_iterator<int> start(is), end;
		std::vector<int> numbers(start, end);
		//std::cout << "Read " << numbers.size() << " numbers" << std::endl;
		//std::copy(numbers.begin(), numbers.end(),
		//std::ostream_iterator<int>(std::cout, " "));
		//printf("\n");
		//quicksort(numbers, 0, numbers.size() - 1);


		//print the numbers to stdout
		//std::cout << "numbers read in:\n";
		//std::copy(numbers.begin(), numbers.end(),
		//std::ostream_iterator<int>(std::cout, " "));
		//std::cout << std::endl;
		int k = atoi(argv[2]);
		int n = numbers.size();
		int a[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = numbers[i];
		}
		//for(int i = 0; i < n; i++)
		//	printf("%d ", a[i]);
		//printf("\n");



		/*
		   int n;
		   cout<<"Enter the size of the array"<<endl;
		   cin>>n;
		   int a[n];
		   cout<<"Enter the elements in the array"<<endl;
		   for(int i=1;i<=n;i++)
		   {
		   cin>>a[i];
		   }*/

		//cout<<"sorting using randomized quick sort"<<endl;
		int p=0,r=n;
		//    if(n > k)
		R_QUICKSORT(a,p,r,k, n, stats);
		//    else
		//    isort(a,a,p,r,n);
		//cout<<"sorted form"<<endl;
		//for(int i=0;i<n;i++)
		//{
		//	printf("%d ", a[i]);
		//	//cout<<"a["<<i<<"]="<<a[i]<<endl;
		//}
		//printf("\n");
	//	for(int i = 0; i < 3; i++){
	//	if(i = 0) printf("Partitioning Stages:  ");
	//	else if(i = 1) printf("Exchanges:  ");
	//	else if(i = 2) printf("Compares:  ");
	//	printf("%d\n", stats[i]);
	//	}
	 	printf("Partitioning States:  %d\n", stats[0]);
                printf("Exchanges:  %d\n", stats[1]);
                printf("Compares:  %d\n", stats[2]);
	} else    printf("Usage: a.out <filename> <k>\n");
	return 0;
}

void R_QUICKSORT(int a[],int p,int r, int k, int n, int stats[])
{
	int q;
	if(p<r)
	{
		stats[0] += 1;
		q=R_PARTITION(a,p,r,stats);
		//         int b[q-1-p+1];
		//         int c[r-(q+1)+1];
		if(q-1-p+1 > k)
			R_QUICKSORT(a,p,q-1, k,n, stats);
		else
			//         {
			//	 for(int it = 0; it < q-1-p+1; it++)
			//	 	b[it] = a[it + p];
			//	 if(q > 0)
			//	 isort(a,b, p, q-1, q-1-p+1);
			insertionSort(a,p,q-1,stats);
		//	 }

		if(r-(q+1)+1 > k)
			R_QUICKSORT(a,q+1,r,k,n, stats);
		else
			//         {
			insertionSort(a,q+1,r,stats);
		//	 for(int it = 0; it < r-(q+1)+1; it++)
		//        	c[it] = a[it + q + 1];
		//	 if(q<n-1)
		//         isort(a,c,q+1,r, r-(q+1)+1);
		//         } 
	}
}
void isort(int a[], int b[], int l, int r, int size)
{
	// printf("\n");
	// for(int i = 0; i < size; i++)
	// printf("%d ",b[i]);
	// printf("\n");
	int j, temp;

	for (int i = 0; i < size; i++){
		j = i;

		while (j > 0 && b[j] < b[j-1]){
			temp = b[j];
			b[j] = b[j-1];
			b[j-1] = temp;
			j--;
		}
	}
	for(int i = 0; i < size; i++)
		a[l+i] = b[i];
}
void insertionSort(int intArray[], int left, int right, int stats[]) {
	int in, out;

	for (out = left + 1; out <= right; out++) {
		int temp = intArray[out];
		in = out;

		while (in > left && intArray[in - 1] >= temp) {
			stats[1] += 1;
			intArray[in] = intArray[in - 1];
			stats[2] += 1;
			--in;
		}
		intArray[in] = temp;
		stats[2] += 1;
	}

	// printf("\n");
	// for(int i = 0; i < size; i++)
	// printf("%d ",a[l+i]);
	// printf("\n");
}


int R_PARTITION(int a[],int p,int r, int stats[])
{ 
	srand(time(NULL));
	int i=p+rand()%(r-p+1);
	int temp;
	temp=a[r];
	a[r]=a[i];
	a[i]=temp;
	stats[2] += 1;
	return PARTITION(a,p,r,stats);
}

int PARTITION(int a[],int p,int r, int stats[])
{
	int temp,temp1;
	int x=a[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			stats[1] += 1;
			i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			stats[2] += 1;
		}
	}
	temp1=a[i+1];
	a[i+1]=a[r];
	a[r]=temp1;
	stats[2] += 1;
	return i+1;
}
