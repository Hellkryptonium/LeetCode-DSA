class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if(set.contains(num)) {
                return num;
            }
            set.insert(num);
        }
        return -1;
    }
};