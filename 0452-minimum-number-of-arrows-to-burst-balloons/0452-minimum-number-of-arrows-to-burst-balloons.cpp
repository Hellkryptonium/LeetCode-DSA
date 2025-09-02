class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        //Step 1: Sort by ending coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});

        // Step 2: place first arrow at the end of the first balloon
        int arrows = 1;
        long long arrowPos = points[0][1];

        // Step 3: Traverse the balloons
        for(int i=1; i<points.size(); i++) {
            if(points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
        }
        return arrows;
    }
};