 #include<iostream>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int arr[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    if(i==0)arr[i][j]=j;
                    else arr[i][j]=i;
                    continue;
                }
                if(word1[i-1]==word2[j-1])arr[i][j]=arr[i-1][j-1];
                else{
                    arr[i][j]=std::min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]})+1;
                }
            }
        }
        return arr[n][m];
    }
};
