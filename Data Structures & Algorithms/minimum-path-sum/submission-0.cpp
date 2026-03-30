class Solution {
    int m, n;
    int INF = 1e9;
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
    }
private:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){

        if(i < 0 || i >= m || j < 0 || j >= n) return INF;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m - 1 && j == n - 1){
            return dp[i][j] = grid[i][j];
        }

        int down = solve(i + 1, j, grid, dp);
        int right = solve(i, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }
};