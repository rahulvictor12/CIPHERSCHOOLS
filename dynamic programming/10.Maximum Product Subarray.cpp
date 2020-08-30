 #include<iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector< int>& nums) {
    vector<int> max_dp(nums.size());
    vector<int> min_dp(nums.size());
  
    max_dp[0]=nums[0];
    min_dp[0] = nums[0];
    
    for(int i=1;i<nums.size();i++){
        if(nums[i]<0){
            max_dp[i]=max(nums[i],nums[i] * min_dp[i-1]);
            min_dp[i]=min(nums[i],nums[i]*  max_dp[i-1]);
        }
        else{
            max_dp[i]= max(nums[i],nums[i] * max_dp[i-1]);
            min_dp[i]= min(nums[i],nums[i] * min_dp[i-1]);
        }
    }
   
    return *max_element(max_dp.begin(),max_dp.end());}
};
