#include<iostream>
using namespace std;
class Solution {
public:
    void helper(vector<string>&ans,vector<string>&fans,int limit,string &res, int n, int start){
        if(res.size()==n){
            fans.push_back(res);
            return;
        }
        for(int i =0;i<ans[start].size();i++){
           
                res.push_back(ans[start][i]);
             
                helper(ans,fans,1,res,n,start+1);
                res.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>fans;
        vector<string>ans;
        int n = digits.size();
        if(n==0){
            return fans;
        }
        for(int i =0;i<n;i++){
            
            int x = digits[i]-'0';
            if(x==2){
                ans.push_back("abc");
            }
            else if(x==3){
                 ans.push_back("def");
            }
            else if(x==4){
                ans.push_back("ghi");
            }
            else if(x==5){
                ans.push_back("jkl");
            }
            else if(x==6){
                 ans.push_back("mno");
            }
            else if(x==7){
                 ans.push_back("pqrs");
            }
            else if(x==8){
                ans.push_back("tuv");
            }
            else if(x==9){
                 ans.push_back("wxyz");
            }
        }
        string res = "";
        int start = 0;
        helper(ans,fans,1,res,n, start);
        return fans;
    }
};
