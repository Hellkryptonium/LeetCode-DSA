class Solution {
public:
    int dp[205][205];
    bool vis[205][205];

    int solve(int row, int col, vector<vector<int>>& triangle) {
        if(row == triangle.size() - 1) {
            return triangle[row][col];
        }

        if(vis[row][col]) {
            return dp[row][col];
        }

        int down = solve(row+1, col, triangle);
        int diag = solve(row+1, col+1, triangle);

        dp[row][col] = triangle[row][col] + min(down, diag);
        vis[row][col] = true;
        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        memset(vis, false, sizeof(vis));
        return solve(0, 0, triangle);
    }
};