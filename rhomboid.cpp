#include<iostream>
using namespace std;

void rhomboid(int rows)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows-i;j++)
		{
			cout<<" ";
		}
		for(j=1;j<=rows;j++)
		{
			cout<<"*";
		
		}
			cout<<"\n";
	}
}
void printpattern(int rows)
{
	cout<<"pattern";
	cout<<"\n";
	rhomboid(rows);
}
int main()
{
	int rows=5;
	printpattern(rows);
	
}
