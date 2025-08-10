class Solution {
public:
    int binarySearch(const vector<int>& prefix, int start, int target) {
        int left = start, right = prefix.size() - 1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(prefix[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int minLen = INT_MAX;

        for(int i=0; i<n; i++) {
            int required = target + prefix[i];
            int j = binarySearch(prefix, i+1, required);
            if(j != -1) {
                minLen = min(minLen, j-i);
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};