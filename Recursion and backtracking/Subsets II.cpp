 #include<iostream>
using namespace std;

 class Solution {
public:
    void sub(set<vector<int>> &dup ,vector<int>& nums ,vector<int> &tmp,int i,int n )
    {
        if(i==n) {dup.insert(tmp);return;}
        dup.insert(tmp);
        tmp.push_back(nums[i]);
        sub(dup,nums,tmp,i+1,n);
        tmp.pop_back();
        sub(dup,nums,tmp,i+1,n);
       
    }
     
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         set<vector<int>> dup;
         vector<int> tmp;
        vector<vector<int>> res;
         sub(dup,nums,tmp,0,nums.size());
        
         for(auto x:dup) res.push_back(x);
             return res;
    }
};
