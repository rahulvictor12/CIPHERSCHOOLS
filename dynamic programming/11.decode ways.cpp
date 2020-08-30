 #include<iostream>
using namespace std;
class Solution {
public:
	// isValid function checks if the string is valid or not.
    bool isValid(char a) {
        return (a == '0') ? false: true;
    }
    bool isValid(char a, char b) {
        return ((a == '1') || (a == '2' && b <= '6')) ? true: false;    
    }
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = isValid(s[0])? 1:0;
        for(int i=2;i<=n;i++) {
            if(isValid(s[i-1])) {
                dp[i] += dp[i-1];
            }
            if(isValid(s[i-2], s[i-1])) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
