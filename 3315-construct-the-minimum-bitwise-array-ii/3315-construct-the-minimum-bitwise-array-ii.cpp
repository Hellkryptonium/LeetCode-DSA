class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int p : nums) {
            if (p == 2) { // only even prime
                ans.push_back(-1);
                continue;
            }

            long long best = (1LL<<62);
            for (int b = 0; b <= 31; b++) {
                if ((p >> b) & 1) {
                    long long x = (long long)p - (1LL << b);
                    if (x >= 0 && ( (x | (x + 1)) == p )) {
                        best = min(best, x);
                    }
                }
            }
            ans.push_back(best == (1LL<<62) ? -1 : (int)best);
        }
        return ans;
    }
};
