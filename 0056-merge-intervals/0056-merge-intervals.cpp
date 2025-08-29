class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //1) sort intervals by start
        sort(intervals.begin(), intervals.end());

        //2) this will hold the merged, non-overlapping intervals.
        vector<vector<int>> merged;

        //3) scan left -> right, merging as we go

        for(auto interval : intervals) {
            if(merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};