#include<iostream>
using namespace std;

int binarytodecimal(int n)
{
	int mun=n;
	int dec_value=0;
	int base=1;//as base value of binary digits is 2^0=1
	int temp=n;
	
	while(temp)
	{
		int last=temp%10;
		temp=temp/10;
		dec_value+=last*base;
		base=base*2;
		
	}
	return dec_value;
 } 
int main()
{
    int num;
    cout<<"enter the number";
    cin>>num;
	cout<<binarytodecimal(num)<<endl;
	
}
