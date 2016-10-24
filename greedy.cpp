#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int* changegreedy(int arr[], int A){
// get size of arr[] -> O(n)
	int size = 0;
	for (int i = 0; arr[i] != '\0'; ++i){
		size = i;
        	cout << "arr[i]" << i << "]: " << arr[i] << endl;
	}
cout << "size is: " << size << endl;
	int* returnA = new int[size];

// to really know the most valuable coins we have to sort it
        sort(arr, arr + size);
cout << "sorting" << endl;
         	for (int i = 0; arr[i] != '\0'; ++i){
        	cout << "arr[i]" << i << "]: " << arr[i] << endl;
         	}

// worst case O(n)
cout << "making returnArray" << endl;
	for(int i = size-1 ; A > 0; --i){
		while (A >= arr[i]){
			A = A - arr[i];	
			returnA[i] += 1;
		//cout << "arr[i] is: " << arr[i] << endl;
		//cout << "A is: " << A << endl;
		}	
        	cout << "returnA[" << i << "]: " << returnA[i] << endl;
	}
	return returnA;
}

int main() {
	FILE * file;
	file = fopen("Amount.txt", "r");
	int test[4] = {1,2,4,8};
	//int test[4] = {1,3,7,12};
	int* answer = changegreedy(test, 15);
	cout << "[";
	for (int i = 0; answer[i] != '\0'; ++i){
		cout << answer[i];
	}
	cout << "]" << endl;;
    return 0;
}
