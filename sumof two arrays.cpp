//Sum of 2 arrays
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
 int a[20],b[20],sum[20];
 int c,n;
 
 cout<<"number of elements in array";
 cin>>n;
 cout<<"enter elements of first array";
  for(c=0;c<n;c++)
  {
  	cin>>a[c];
	  }	
 cout<<"enter elements of second array";
   for(c=0;c<n;c++)
   {
   	cin>>b[c];
   }
 cout<<"sum of elements of arrays"<<endl;
   for(c=0;c<n;c++)
   {
   	sum[c]=a[c]+b[c];
   	cout<<sum[c]<<endl;
   }
   return 0;
}
