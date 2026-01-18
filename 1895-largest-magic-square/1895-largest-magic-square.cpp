#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        // rowPref[r][c+1]
        vector<vector<long long>> rowPref(m, vector<long long>(n + 1, 0));
        // colPref[c][r+1]
        vector<vector<long long>> colPref(n, vector<long long>(m + 1, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                rowPref[r][c + 1] = rowPref[r][c] + grid[r][c];
            }
        }
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < m; r++) {
                colPref[c][r + 1] = colPref[c][r] + grid[r][c];
            }
        }

        // diag1: main diagonal prefix (↘), size (m+1)x(n+1)
        vector<vector<long long>> diag1(m + 1, vector<long long>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                diag1[r + 1][c + 1] = diag1[r][c] + grid[r][c];
            }
        }

        // diag2: anti diagonal prefix (↙), size (m+1)x(n+1) but shifted indexing
        // We'll use diag2[r+1][c] = diag2[r][c+1] + grid[r][c]
        vector<vector<long long>> diag2(m + 1, vector<long long>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                diag2[r + 1][c] = diag2[r][c + 1] + grid[r][c];
            }
        }

        auto rowSum = [&](int r, int c1, int c2) -> long long {
            // inclusive c1..c2
            return rowPref[r][c2 + 1] - rowPref[r][c1];
        };
        auto colSum = [&](int c, int r1, int r2) -> long long {
            // inclusive r1..r2
            return colPref[c][r2 + 1] - colPref[c][r1];
        };
        auto mainDiagSum = [&](int r, int c, int k) -> long long {
            // top-left (r,c), size k, diagonal from (r,c) to (r+k-1,c+k-1)
            int r2 = r + k;
            int c2 = c + k;
            return diag1[r2][c2] - diag1[r][c];
        };
        auto antiDiagSum = [&](int r, int c, int k) -> long long {
            // top-left (r,c), size k, anti-diagonal from (r,c+k-1) to (r+k-1,c)
            // Using diag2: diag2[r+1][c] = diag2[r][c+1] + grid[r][c]
            // Sum along anti diag equals diag2[r+k][c] - diag2[r][c+k]
            return diag2[r + k][c] - diag2[r][c + k];
        };

        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) { // k=1 always works, handle at end
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    long long target = rowSum(i, j, j + k - 1);

                    // diagonals
                    if (mainDiagSum(i, j, k) != target) continue;
                    if (antiDiagSum(i, j, k) != target) continue;

                    bool ok = true;

                    // rows
                    for (int r = i; r < i + k; r++) {
                        if (rowSum(r, j, j + k - 1) != target) { ok = false; break; }
                    }
                    if (!ok) continue;

                    // cols
                    for (int c = j; c < j + k; c++) {
                        if (colSum(c, i, i + k - 1) != target) { ok = false; break; }
                    }
                    if (ok) return k; // largest first, so return immediately
                }
            }
        }

        return 1;
    }
};
