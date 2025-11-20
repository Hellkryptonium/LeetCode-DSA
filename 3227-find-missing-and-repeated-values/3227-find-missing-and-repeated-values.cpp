class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1, 0);
        vector<int> ans(2);

        for(const auto& row : grid) {
            for(int value : row) {
                freq[value]++;

                if(freq[value] == 2) {
                    ans[0] = value;
                }
            }
        }

        for(int i=1; i<=n*n; i++) {
            if(freq[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
};