#include<iostream>
using namespace std;

class Solution {
public:
    void solution(vector<vector<int>>&ans,vector<int> temp,int n,int k,unordered_map<int,int> &previous){
        // cout<<"n= "<<n<<endl;
        if(temp.size()==k){
            if(n==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(n==0)return;
        for(int i=temp.size()==0?9:temp.back()-1;i>=1;i--){
            if(n-i>=0 and previous.count(i)==0){
                temp.push_back(i);
                previous[i]=1;
                solution(ans,temp,n-i,k,previous);
                temp.pop_back();
                previous.erase(i);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_map<int,int> previous;
        solution(ans,temp,n,k,previous);
        return ans;
        for(auto &it:ans)
            sort(it.begin(),it.end());
        set<vector<int>> z;
        for(auto it:ans)z.insert(it);
        ans.clear();
        for(auto it:z)ans.push_back(it);
        return ans;
    }
};
