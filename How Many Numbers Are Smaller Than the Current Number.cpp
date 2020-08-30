#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count=0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {   count=0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[i]>nums[j])
                {
                    count+=1;
                }
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};
