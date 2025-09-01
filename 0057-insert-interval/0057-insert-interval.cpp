class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        int ns = newInterval[0], ne = newInterval[1];

        while(i<n && intervals[i][1] < ns) {
            res.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0] <= ne) {
            ns = min(ns, intervals[i][0]);
            ne = max(ne, intervals[i][1]);
            i++;
        }
        res.push_back({ns,ne});

        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};