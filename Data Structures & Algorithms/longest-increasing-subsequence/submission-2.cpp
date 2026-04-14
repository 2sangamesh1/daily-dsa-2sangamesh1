class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solve(-1, 0, nums, dp);
    }
private:
    int solve(int prev, int curr, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(curr >= n) return 0;
        if(dp[prev + 1][curr] != -1) return dp[prev + 1][curr];
        int one = 0, two = 0;
        if(prev == -1 || nums[curr] > nums[prev]) one = 1 + solve(curr, curr + 1, nums, dp);
        two = solve(prev, curr + 1, nums, dp);

        return dp[prev + 1][curr] = max(one, two);
    }
};
