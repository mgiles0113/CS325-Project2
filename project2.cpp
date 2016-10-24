//Mark Giles
//George Sustare
//Ryan Fleming
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

//algorithm 1
//brute force



//algorithm 2
//greedy
int changegreedy(int VSize, int in[], int out[], int A){
//to really know the most valuable coins we have to sort it
	sort(in, in);
//worst case O(n)
	int numCoins = 0;
	for(int i = VSize-1 ; A > 0; --i){
		while (A >= in[i]){
			A = A - in[i];
			out[i] += 1;
			numCoins += 1;
		}
	}
	return numCoins;
}


//algorithm 3
//dynamic programming
int changedp(int VSize, int V[], int outputArray[], int A)
{
	int i, j = 0;
	//make table indexed by values of change
	int **T;
	T = (int**) malloc(sizeof(int*)*VSize);
	for (i = 0; i < VSize; i++)
	{
		//keep track of indices of maximum subarray
		T[i] = (int*) malloc(sizeof(int)*(A + 1));
		for (j = 0; j <= A; j++)
		{
			if (i == 0)
			{
				//correct coin value
				T[i][j] = j;
			}
			//if coin value is too high
			else if (V[i] > j)
			{
				//go back up one row
				T[i][j] = T[i - 1][j];
			}
			//or its the smaller of the row above or the column back one coin value
			else
			{
				if (T[i - 1][j] > (T[i][j - V[i]] + 1))
					T[i][j] = (T[i][j - V[i]] + 1);
				else	
					T[i][j] = T[i - 1][j];
			}
		}
	}
	//minimum number of coins needed
	int minimum = 0;
	//go backwars through table
	i = VSize - 1;
	j = A;
	while (i >= 1 && j > 0)
	{
		if(T[i][j] == T[i - 1][j])
		{
			//no coin in index, go up one row
			i--;
		}
		//if there is a coin in index
		else
		{
			//go back to previous coin value
			j -= V[i];	 	
			//add this voic to outputArray
			outputArray[i]++;
			minimum++;
			//take out coin value from amount needed	
			A -= V[i];
		}
	}
	//fill amount remaining with pennies
	outputArray[0] = A;
	minimum += A;
	//cleanup
	for (i = 0; i < VSize; i++)
	{
		delete T[i];
	}
	delete T;	
	return minimum;
}



int main() 
{
	int VSize = 4;
	int V[4] = {1, 3, 7, 12};
	int A = 31;
	int outputArray[4] = {0, 0, 0, 0};
	int m = changedp(VSize, V, outputArray, A);
	cout << m << endl;
	for (int i = 0; i < VSize; i ++)
		cout << outputArray[i] <<endl;

	// Greedy Algorithm tests
        cout << endl << "**************************************" << endl;
	cout << "gegreedy() test " << endl;
        cout << "**************************************" << endl;
        cout << "testing with C = [1,2,4,8] and m = 15" << endl;
        int coins1[4] = {1,2,4,8};
        int change1 = 15;
        int VSize1 = 4;
        int outputArray1[4] = {0,0,0,0};
        int m1 = changegreedy(VSize1, coins1, outputArray1, change1);
        cout << "m = " << m1 << endl;
        cout << "[";
        for (int i = 0; i < VSize1; ++i){
                cout << outputArray[i];
        }
        cout << "]" << endl;;

        cout << "**************************************" << endl;
        cout << "testing with C = [1,3,7,12] and m = 29" << endl;
        int coins2[4] = {1,3,7,12};
        int change2 = 29;
        int VSize2 = 4;
        int outputArray2[4] = {0,0,0,0};
        int m2 = changegreedy(VSize2, coins2, outputArray2, change2);
        cout << "m = " << m2 << endl;
        cout << "[";
        for (int i = 0; i < VSize2; ++i){
                cout << outputArray2[i];
        }
        cout << "]" << endl;;

        cout << "**************************************" << endl;
        cout << "testing with C = [1,3,7,12] and m = 29" << endl;
        int coins3[4] = {1,3,7,12};
        int change3 = 31;
        int VSize3 = 4;
        int outputArray3[4] = {0,0,0,0};
        int m3 = changegreedy(VSize3, coins3, outputArray3, change3);
        cout << "m = " << m3 << endl;
        cout << "[";
        for (int i = 0; i < VSize3; ++i){
                cout << outputArray3[i];
        }
        cout << "]" << endl;;
        // end Greedy Algorithm
        return 0;
}  
