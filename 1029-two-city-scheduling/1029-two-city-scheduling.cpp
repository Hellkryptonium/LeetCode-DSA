class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int ans = 0;

        ranges::sort(costs, ranges::less{}, [](vector<int>& cost) {return cost[0]-cost[1];});

        for(int i=0; i<n; i++) {
            ans += costs[i][0] + costs[i+n][1];
        }

        return ans;
    }
};