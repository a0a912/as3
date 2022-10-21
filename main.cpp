#include "a3.h"
#include <iostream>

using namespace std;


int main()
{
	int arr[] = {1,2,3,4,5};
	cout<<"***1. Cartesian Product TEST N = 5***"<<endl;
	cout<<cartesianProduct(arr,5)<<endl;

	cout<<endl;

	cout<<"***2. TRIANGLE N = 5***"<<endl;
	cout<<triangle(5)<<endl;

	cout<<endl;

	cout<<"***3. REMOVE DUPLICATES N = 5***"<<endl;
	int cost = 0;
	int n = 5;

	int arr1[n] = {1,2,3,4,5};
	removeDuplicates(arr1, n, cost);
	cout<<"n: " <<n<<"diff/Worst: "<<cost<<endl;

	cost = 0;
	int arr2[n] = {1,1,1,1,1};
	removeDuplicates(arr2, n, cost);
	cout<<"n: "<<n<<" same/Best: "<<cost<<endl;

	cout<<endl;

	cout<<"***4. Matrix N = 5 ***"<<endl;
	int* matrix;
	int count =0;
	matrixSelfMultiply(matrix, 5, count);
	cout<<count<<endl;

	cout<<endl;

	cout<<"***5. Sorting N = 5***"<<endl;
	n = 5;
	int arr3[n] = {5,4,3,2,1};
	cout<<ssort(arr3, n, 0)<<endl;

	cout<<endl;

	cout<<"***6. Pattern N = 4***"<<endl;
	cout<<pattern(4,0)<<endl;
}
