 #include<iostream>
using namespace std;
class Solution {
public:
    
    void populateSentence(string &s, int start, unordered_set<string> &dict, vector<bool> &dp, string curr, vector<string> &res) {
        if(start == s.size()) {
            string temp = curr.substr(0, curr.size()-1);
            res.push_back(temp);
            return;
        }
        
        //Recursive formulation
        //Try sll partitions
        
        int n = s.size();
        string t="";
        for(int i = start;i<n;i++) {
            t+=s[i];
            if(dict.find(t) == dict.end())
                continue;
            if(dp[i+1])
                populateSentence(s, i+1, dict, dp, curr+t+" ",res);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.size();
        
        unordered_set<string> dict;
        
        for(int i=0;i<wordDict.size();i++) 
            dict.insert(wordDict[i]);
        
        string t="";
        
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for(int i=n-1;i>0;i--) {
            t="";
            for(int j=i;j<n;j++) {
                t+=s[j];
                
                if(dict.find(t) == dict.end())
                    continue;
                
                if(dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        vector<string> res;
        populateSentence(s, 0, dict, dp, "",res);
        return res;
    }
};
