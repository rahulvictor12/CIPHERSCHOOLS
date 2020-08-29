#include<iostream>
using namespace std;

class Solution {
public:
    int R,C;
    bool isvalid(int r, int c, bool visited[][105]){
        if(r<0||r>=R||c<0||c>=C){return 0;}
        return visited[r][c]==0;
    }
    bool find(int r, int c, vector<vector<char>>& board, string& word, int ind, bool visited[][105]){
        if(ind>=word.size()){return 1;}
        if(!isvalid(r,c,visited)){return 0;}
        if(board[r][c]!=word[ind]){return 0;}
        visited[r][c]=1;
            if(find(r+1,c,board,word,ind+1,visited)){
                return 1;
            }
            if(find(r,c+1,board,word,ind+1,visited)){
                return 1;
            }
            if(find(r-1,c,board,word,ind+1,visited)){
                return 1;
            }
            if(find(r,c-1,board,word,ind+1,visited)){
                return 1;
            }
        visited[r][c]=0;
        return 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        R=board.size();C=board[0].size();
        for(int i=0;i<words.size();i++){
            bool b=0;
            for(int r=0;r<board.size()&&b==0;r++){
                for(int c=0;c<board[0].size()&&b==0;c++){
                    bool visited[105][105];
                    memset(visited,0,sizeof(visited));
                    if(find(r,c,board,words[i],0,visited)){
                        ans.push_back(words[i]);b=1;
                    }
                }
            }
        }
        return ans;
    }
};
