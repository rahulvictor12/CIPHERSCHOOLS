//No.7 IS ARRAY MIRROR INVERSE

#include<iostream>
#include<cmath>
using namespace std;
bool ismirrorinverse(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[arr[i]]!=i)
		return false;
	}
	return true;
}
int main()
{
 int arr[20];
 int c,size;
 cout<<"size of array"<<endl;
 cin>>size;
 int n=sizeof(arr)/sizeof(arr[0]);
 cout<<"enter elements of first array";
  for(c=0;c<size;c++)
  {
  	cin>>arr[c];
 }	
 if(ismirrorinverse(arr,n))
    cout<<"yes";
	 
 else
    cout<<"no";	 
	 
return 0;	 
	 }
