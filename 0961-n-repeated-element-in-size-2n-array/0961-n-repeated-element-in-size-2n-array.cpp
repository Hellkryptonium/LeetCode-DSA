class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int num : nums) {
            map[num]++;
        }

        for(int num : nums) {
            if(map[num] == n/2) {
                return num;
            }
        }
        return -1;
    }
};