class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;

        for(int num : nums) {
            if(num <= 0 || num >= n) return false;
            map[num]++;
        }

        if(map[n-1] != 2) {
            return false;
        }

        for(int i=1; i<=n-2; i++) {
            if(map[i] != 1) {
                return false;
            }
        }

        return true;
    }
};