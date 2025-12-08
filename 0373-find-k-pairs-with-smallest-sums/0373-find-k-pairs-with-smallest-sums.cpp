class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        if(nums1.empty() || nums2.empty()) return result;

        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0]+nums2[0], 0, 0});
        visited.insert({0,0});

        while(k-- && !pq.empty()) {
            auto[sum, i, j] = pq.top();
            pq.pop();

            result.push_back({nums1[i], nums2[j]});

            if(j+1 < nums2.size() && visited.insert({i, j+1}).second) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }

            if(i+1 < nums1.size() && visited.insert({i+1, j}).second) {
                pq.push({nums1[i+1]+nums2[j], i+1, j});
            }
        }

        return result;
    }
};