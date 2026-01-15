class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // find longest consecutive sequence length
        auto longest = [&](vector<int>& bars) {
            int best = 1, cur = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1) {
                    cur++;
                } else {
                    cur = 1;
                }
                best = max(best, cur);
            }
            return best + 1;   // side = consecutive gaps + 1
        };

        int hSide = longest(hBars);
        int vSide = longest(vBars);

        int side = min(hSide, vSide);

        return side * side;
    }
};
