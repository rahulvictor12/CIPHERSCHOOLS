 #include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        //empty array case
        if(nums.size() == 0)
            return 0;
        
        vector<int> arr(nums.size(), 1); 
  
        //dynamic approach: we fill the small sub-problems and from them build up the big sub-problems
        for (int i = 1; i < nums.size(); i++)  
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && arr[i] < arr[j] + 1)  
                    arr[i] = arr[j] + 1;
            }
        } 
  
        return *max_element(arr.begin(), arr.end() ); 
    } 
    
};
