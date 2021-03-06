#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char ch: t)
            mp[ch]++;
        int n=s.size(), m=t.size(), j=0, cnt=0, ans=n+1, idx;
        for(int i=0; i<n; i++){
            if(mp[s[i]]>0) cnt++;
            mp[s[i]]--;
            while(cnt==m){
                if(ans>i-j+1){
                    ans=i-j+1;
                    idx=j;
                }
                if(mp[s[j]]==0) cnt--;
                mp[s[j]]++;
                j++;
            }
        }
        if(ans==n+1) return "";
        else return s.substr(idx, ans);
    }
};
