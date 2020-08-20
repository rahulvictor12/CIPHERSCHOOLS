//no 9 move zeros
#include<iostream>
#include<cmath>
using namespace std;

void pusharrayzeros(int arr[],int n)
{
	int count=0;//count
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			arr[count++]=arr[i];
		}
	}
	while(count<n)
	{
		arr[count++]=0;
	}
}
int main()
{
	int arr[5];
	int n=sizeof(arr)/ sizeof (arr[0]);
	for(int i=0;i<n;i++)
	{   
	    cout<<" enter the values : \n";
		cin>>arr[i];
	}
	pusharrayzeros(arr,n);
	cout<<"after pushing";
	for(int i=0;i<n;i++)
	{   
	cout<<arr[i]<<endl;
	}
	return 0;
}
