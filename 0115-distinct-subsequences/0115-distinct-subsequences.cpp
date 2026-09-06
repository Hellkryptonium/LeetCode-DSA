class Solution {
public:
    int n, m;
    string s, t;
    vector<vector<long long>> dp;

    long long solve(int i, int j) {
        // We formed the entire target
        if (j == m)
            return 1;

        // s is exhausted but target isn't
        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Don't use s[i]
        long long ans = solve(i + 1, j);

        // Use s[i] if it matches t[j]
        if (s[i] == t[j]) {
            ans += solve(i + 1, j + 1);
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;

        n = s.size();
        m = t.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0);
    }
};