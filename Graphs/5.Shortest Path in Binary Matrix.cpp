 #include<iostream>
using namespace std;
class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) {
            return -1;
        }
        if(row == 1) return 1;
        int dist[row + 1][col + 1];
        
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                dist[i][j] = row*col;
                
            }
        }
        queue<pair<int, int> > que;
        
        que.push(make_pair(0,0));  
        grid[0][0]=1;
        dist[0][0]=1;
        
        vector<pair<int,int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        
        while(!que.empty()){
     
            pair<int, int> cell = que.front(); 
            que.pop();
            int cr = cell.first; 
            int cc = cell.second; 
            for(int i=0; i< dir.size();i++){
                int nr = cr+dir[i].first;
                int nc = cc+dir[i].second;
                if(nc<0 || nc>=col|| nr<0 || nr>=row|| grid[nr][nc]!=0) continue;
              
                grid[nr][nc] = 1;
          
                if(dist[nr][nc] > dist[cr][cc] + 1)
                    dist[nr][nc] = dist[cr][cc] + 1;
                

                que.push(make_pair(nr, nc));
                
                if(nr == row-1 && nc == col-1) {
                    return dist[nr][nc];
                }
            }
            
        }
        return -1;
    }
};
