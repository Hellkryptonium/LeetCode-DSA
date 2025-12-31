class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int day, int k, int holding, vector<int>& prices) {
        if(day == n || k == 0) return 0;

        if(dp[day][k][holding] != -1) {
            return dp[day][k][holding];
        }

        int profit = 0;

        if(holding == 0) {
            int skip = solve(day+1, k, 0, prices);
            int buy = -prices[day] + solve(day+1, k, 1, prices);
            profit = max(skip, buy);
        } else {
            int skip = solve(day+1, k, 1, prices);
            int sell = prices[day] + solve(day+1, k-1, 0, prices);
            profit = max(skip, sell);
        }

        return dp[day][k][holding] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, k, 0, prices);
    }
};