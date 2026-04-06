class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(4);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        if(n < 3) return dp[n];
        int i = 2;
        while(i < n){
            dp[3] = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1], dp[1] = dp[2], dp[2] = dp[3];
            i++;
        }
        return dp[3];
    }
};