#include<iostream>
using namespace std;

int main()
{
int num,r,c;//r=rows,c=columns
cout<<"Enter number of rows in odd number ";
cin>>num;
if(num%2==0)
{
return 0;
}
for(r=0; r<num; r++)
{
for(c=0; c<num; c++)
{
if(r<num/2)
{
if(c<num/2)
{
if(c==0)
cout<<"*";
else
cout<<" ";
}
else if(c==num/2)
cout<<"*";
else
{
if(r==0)
cout<<"*";
}
}
else if(r==num/2)
cout<<"*";
else
{
if(c==num/2 || c==num-1)
cout<<"*";
else if(r==num-1)
{
if(c<=num/2 || c==num-1)
cout<<"*";
else
cout<<" ";
}
else
cout<<" ";
}
}
cout<<endl;
}
}
