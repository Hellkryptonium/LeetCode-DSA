class Solution {
public:
    int solve(int n, vector<int>& dp) {

        if(dp[n] != -1) return dp[n];
        int val = solve(n-1,dp) + solve(n-2,dp);
        dp[n] = val;
        return val;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return solve(n, dp);
    }
};