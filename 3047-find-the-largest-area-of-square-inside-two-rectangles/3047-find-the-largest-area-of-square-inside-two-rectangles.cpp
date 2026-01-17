#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                               vector<vector<int>>& topRight) {
        int n = (int)bottomLeft.size();
        long long best = 0;

        for (int i = 0; i < n; i++) {
            long long ax1 = bottomLeft[i][0], ay1 = bottomLeft[i][1];
            long long ax2 = topRight[i][0],   ay2 = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                long long bx1 = bottomLeft[j][0], by1 = bottomLeft[j][1];
                long long bx2 = topRight[j][0],   by2 = topRight[j][1];

                long long interW = min(ax2, bx2) - max(ax1, bx1);
                long long interH = min(ay2, by2) - max(ay1, by1);

                if (interW > 0 && interH > 0) {
                    long long side = min(interW, interH);
                    best = max(best, side * side);
                }
            }
        }
        return best;
    }
};
