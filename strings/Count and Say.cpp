#include<iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans=countAndSay(n-1),temp="";
        for(int i=0;i<ans.length();i++)
        {
            int count=1;
            while( i+1<ans.length() && ans[i]==ans[i+1])
            {i++;count++;}
            temp+=count+'0';
            temp+=ans[i];
        }
        return temp;
    }
};
