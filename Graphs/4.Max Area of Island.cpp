 #include<iostream>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
		int res = 0;
		for(int i = 0; i < grid.size();i++)
		{
			for(int j = 0; j<grid[0].size();j++)
			{
				if(grid[i][j] == 1)
				{
					int area = 0;
					combine(grid,area,i,j);
					res = max(res,area);
				}
			}
		}
		return res;
    }
private:
	void combine(vector<vector<int>>& grid,int &area,int row,int col)
	{
		if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() ) return;
		else if(grid[row][col] == 1)
		{
			grid[row][col]= 2;
			area++;
			combine(grid,area,row,col+1);
			combine(grid,area,row,col-1);
			combine(grid,area,row-1,col);
			combine(grid,area,row+1,col);
		}
	}
};

