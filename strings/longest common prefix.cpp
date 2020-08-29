#include<iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        int n = strs.size();
        int i=0;
        string ans = "";
        int len = strs[0].size();
        for(int k=0; k<len; k++){
            char c = strs[0][i];
            for(int j=0; j<n; j++){
                if(strs[j][i] != c){
                    return ans; 
                }
            }
            ans += c;
            i++;
        }
        return ans;
    }
};
