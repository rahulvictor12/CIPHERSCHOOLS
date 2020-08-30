
 #include<iostream>
using namespace std;
class Solution {
public:
	int mat[101][101] = {0};
	int uniquePaths(int m, int n) {


		if(mat[m][n] != 0)
			return mat[m][n];

		if(m < 1 || n < 1)
			return 0;
		if(m == 1 && n == 1)
			return 1;
		return mat[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);

	}
};
