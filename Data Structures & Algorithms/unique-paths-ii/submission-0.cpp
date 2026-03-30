class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[m - 1][n - 1] = 1;
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == m - 1 && j == n - 1) continue;

                long long right = (i + 1 < m) ? dp[i + 1][j] : 0;
                long long down = (j + 1 < n) ? dp[i][j + 1] : 0;

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }
};