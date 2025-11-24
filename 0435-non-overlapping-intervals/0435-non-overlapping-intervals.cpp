class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[0] < b[0];});

        int removals = 0;
        int lastEnd = intervals[0][1];

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] < lastEnd) {
                removals++;
                lastEnd = min(lastEnd, intervals[i][1]);
            } else {
                lastEnd = intervals[i][1];
            }
        }

        return removals;
    }
};