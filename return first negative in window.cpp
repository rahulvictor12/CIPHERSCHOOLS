//First negative in every window of size k
#include<iostream>
using namespace std;

int returnnegative(int arr[],int n,int k)
{
	bool flag;
	for(int i=0;i<(n-k+1);i++)
	{
		flag = false;
		for(int j=0;j<k;j++)	
	{
		if(arr[i+j]<0)
		{
			cout<<"\n the negative number is"<<arr[i+j];
			flag= true;
			break;
			
		}
		if(!flag)
		cout<<"0"<<"\n   ";

	}
	}
};
int main()
{
	int arr[5];
	int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
	}
	returnnegative(arr,n,k);
}
