// C++ program to find Majority 
// element in an array 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find Majority element 
// in an array 
void findMajority(int arr[], int n) 
{ 
	int maxCount = 0; 
	int index = -1; 
	for(int i = 0; i < n; i++) 
	{ 
		int count = 0; 
		for(int j = 0; j < n; j++) 
		{ 
			if(arr[i] == arr[j]) 
			count++; 
		} 
		
		if(count > maxCount) 
		{ 
			maxCount = count; 
			index = i; 
		} 
	} 
	if (maxCount > n/2) 
	cout <<"majority element: "<< arr[index] << endl; 
	
	else
		cout << "No Majority Element" << endl; 
} 

int main() 
{ 
	int arr[5] ;
	int n = sizeof(arr) / sizeof(arr[0]); 
	for(int c=0;c<n;c++)
  {
  	cout<<"enter the elements: ";
  	cin>>arr[c];
 }

	findMajority(arr, n); 

	return 0; 
} 

