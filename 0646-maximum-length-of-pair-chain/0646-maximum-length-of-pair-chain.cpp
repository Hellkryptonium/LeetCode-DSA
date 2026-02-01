class Solution {
public:
    static bool compare(vector<int>& p1, vector<int>& p2) {
        return p1[1] < p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 1;

        int currEnd = pairs[0][1];

        for(int i=1; i<pairs.size(); i++) {
            if(pairs[i][0] > currEnd) {
                ans++;
                currEnd = pairs[i][1];
            }
        }

        return ans;

    }
};