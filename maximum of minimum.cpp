//Find maximum of minimum for every window size in a given array
#include <bits/stdc++.h> 
using namespace std; 

void printMaxOfMin(int arr[], int n) 
{ 
	for (int k=1; k<=n; k++) 
	{ 
		int maxOfMin = INT_MIN; 
 
		for (int i = 0; i <= n-k; i++) 
		{ 
			int min = arr[i]; 
			for (int j = 1; j < k; j++) 
			{ 
				if (arr[i+j] < min) 
					min = arr[i+j]; 
			} 

			if (min > maxOfMin) 
			maxOfMin = min; 
		} 

		cout << maxOfMin << " "; 
	} 
} 

int main() 
{ 
	int arr[7]; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	for(int i=0;i<n;i++)
	{
		cout<<"enter the elements \n";
		cin>>arr[i];
	}
	printMaxOfMin(arr, n); 
	return 0; 
} 


