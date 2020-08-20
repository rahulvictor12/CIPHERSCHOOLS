//sliding window maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int l=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
            if((i-l+1)==k){
                if(mp[pq.top()]>=1){
                ans.push_back(pq.top());}
                else{
                    while(mp[pq.top()]<1){
                        pq.pop();
                    }
                    ans.push_back(pq.top());
                }
                if(l==2){
                    cout<<mp[nums[l]]<<" "<<pq.top()<<" ";
                }
                if(nums[l]==pq.top()){
                    if(mp[nums[l]]==1){
                        pq.pop();
                    }
                }
                mp[nums[l++]]--;
            }
        }
        return ans;
    }
};class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int l=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
            if((i-l+1)==k){
                if(mp[pq.top()]>=1){
                ans.push_back(pq.top());}
                else{
                    while(mp[pq.top()]<1){
                        pq.pop();
                    }
                    ans.push_back(pq.top());
                }
                if(l==2){
                    cout<<mp[nums[l]]<<" "<<pq.top()<<" ";
                }
                if(nums[l]==pq.top()){
                    if(mp[nums[l]]==1){
                        pq.pop();
                    }
                }
                mp[nums[l++]]--;
            }
        }
        return ans;
    }
};
