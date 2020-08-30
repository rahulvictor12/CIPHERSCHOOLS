 #include<iostream>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int l = board[0].size();    
        int w = board.size();       
		
        for (int i = 0; i < l;i++)
            if (board[0][i] == 'O')
                path(board, 0,i);
        
        for (int i = 1; i < w-1; i++)
        {
            if (board[i][0] == 'O')
                path(board, i, 0);
            if (board[i][l-1] == 'O')
                path(board, i, l-1);
        }
        for (int i = 0; i < l;i++)
            if (board[w-1][i] == 'O')
                path(board, w-1, i);

        for(int i = 0; i < w; i++)
            for (int j = 0; j < l; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
    }
    
    void path(vector<vector<char>>& board, int r, int c)
    {
		
        board[r][c] = 'S';
        if (r+1 < board.size())
            if (board[r+1][c] == 'O')
                path(board,r+1,c);
        
        if (c+1 < board[0].size())
            if (board[r][c+1] == 'O')
                path(board, r, c+1);
        
        if (0 < r-1)
            if (board[r-1][c] == 'O')
                path(board, r-1, c);
        
        if (0 < c-1)
            if (board[r][c-1] == 'O')
                path(board, r, c-1);
    }
};
