//no.8 nth fabonnici
#include<iostream>
#include<cmath>
using namespace std;
 //formula for fabonnici series fn=fn-1+fn-2
 int main()
 {
 int t1=0,t2=1,nextTerm=0,n;
 
 cout<<"enter a positive number: \t";
 cin>>n;
 
 cout<<"fibbonaci series"<<t1<<","<<t2<<",";
 nextTerm=t1=t2;
 while(nextTerm<=n)
 {
 	cout<<nextTerm<<",";
 	t1=t2;
 	t2=nextTerm;
 	nextTerm=t1+t2;
 }
 return 0;
 }
