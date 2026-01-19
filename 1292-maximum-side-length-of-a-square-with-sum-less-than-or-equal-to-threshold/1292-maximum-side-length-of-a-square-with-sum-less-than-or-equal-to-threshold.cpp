#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();

        // prefix sums: (m+1) x (n+1)
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            int rowSum = 0;
            for (int j = 1; j <= n; j++) {
                rowSum += mat[i - 1][j - 1];
                pre[i][j] = pre[i - 1][j] + rowSum;
            }
        }

        auto ok = [&](int k) -> bool {
            if (k == 0) return true;
            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {
                    int r2 = r + k, c2 = c + k;
                    int sum = pre[r2][c2] - pre[r][c2] - pre[r2][c] + pre[r][c];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n); // answer in [0, hi]
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2; // upper mid
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
