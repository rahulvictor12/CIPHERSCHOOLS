 #include<iostream>
using namespace std;
class Solution {
public:
    
    int subsetsum(vector<int> nums,int target){
        int dp[1005]={0};
        
        dp[0]=1;
        for(int num:nums){
            for(int i=target;i>=num;i--){
                dp[i]=dp[i]+dp[i-num];
            }
        }
        
        return dp[target];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum<S||((sum+S)&1)==1){
            return 0;
        }else{
            return subsetsum(nums,(sum+S)>>1);
        }
    }
};
