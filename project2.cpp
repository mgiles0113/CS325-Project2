//Ryan Fleming
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

//algorithm 1
//brute force



//algorithm 2
//greedy



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

	return 0;
}  
