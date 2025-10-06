class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> set {nums1.begin(), nums1.end()};
        
        for(int num : nums2) {
            if(set.erase(num)) {
                result.push_back(num);
            }
        }

        return result;
    }
};