class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int lengthOfLongestSubstring(string s) {
        int ans=0,i=0,n=s.size();
        vector<int> track(256,-1);
        for(int j=0;j<n;j++){
            i = (i>track[s[j]]+1)?i:track[s[j]]+1;
            ans = (ans>j-i+1)?ans:j-i+1;
            track[s[j]]=j;
        }
        return ans;
    }
};
