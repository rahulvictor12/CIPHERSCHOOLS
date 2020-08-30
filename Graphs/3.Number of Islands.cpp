 #include<iostream>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;
        
		
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++island_count;
                    sinkIsland(&grid, i, j);
                }
            }
        }
        
        return island_count;
    }
private:
    void sinkIsland(vector<vector<char>>* grid_ptr, int i, int j) {
		
        auto& grid = *grid_ptr;
        

        if (grid[i][j] != '1') return;
        

        grid[i][j] = '0';
        
		
		if (i < grid.size() - 1) sinkIsland(grid_ptr, i + 1, j);  // east
        if (i > 0) sinkIsland(grid_ptr, i - 1, j);  // west
		if (j < grid[i].size() - 1) sinkIsland(grid_ptr, i, j + 1);  // north
        if (j > 0) sinkIsland(grid_ptr, i, j - 1);  // south
    }
};
