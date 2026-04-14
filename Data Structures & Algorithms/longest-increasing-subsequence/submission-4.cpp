class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int take = 0, skip = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + dp[curr + 1][curr + 1];
                }
                skip = dp[prev + 1][curr + 1];

                dp[prev + 1][curr] = max(take, skip);
            }
        }
        return dp[0][0];
    }
};
