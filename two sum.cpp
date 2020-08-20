//two sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
            m.insert({nums[i], i});
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int check = target - nums[i];
            if(m.find(check) != m.end()){
                if(m[check] != i){
                    ans.push_back(i);
                    ans.push_back(m[check]);
                    break;
                }
            }
        }
        return ans;
    }
};
