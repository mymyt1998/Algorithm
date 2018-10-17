 //leetcode不同路径II
 //obstacleGrid中1代表障碍物
 //终点有障碍物无路可走
 class Solution {
 public:
	 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		 int i, j, n = obstacleGrid.size(), m = obstacleGrid[0].size();
		 if (obstacleGrid[n - 1][m - 1])
			 return 0;
		 vector<vector<int> > dp(n, vector<int>(m, 0));
		 dp[0][0] = 1;
		 for (int i = 0; i < n; i++)
		 {
			 for (int j = 0; j < m; j++)
			 {
				 if ((i - 1) >= 0 && !obstacleGrid[i - 1][j])
					 dp[i][j] = dp[i - 1][j];
				 if ((j - 1) >= 0 && !obstacleGrid[i][j - 1])
					 dp[i][j] += dp[i][j - 1];
			 }
		 }
		 return dp[n - 1][m - 1];
	 }
 };
