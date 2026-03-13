class Solution {
public:
    bool searchRotated(vector<int>& nums, int target, int si, int ei) {
        if(si > ei) return false;

        int mid = si + (ei - si)/2;

        if(nums[mid] == target) return true;

        if(nums[si] == nums[mid] && nums[ei] == nums[mid]) {
            return searchRotated(nums, target, si+1, ei-1);
        }

        if(nums[si] <= nums[mid]) {
            if(nums[si] <= target && target <= nums[mid]) {
                return searchRotated(nums, target, si, mid-1);
            } else {
                return searchRotated(nums, target, mid+1, ei);
            }
        } else {
            if(nums[mid] <= target && target <= nums[ei]) {
                return searchRotated(nums, target, mid+1, ei);
            } else {
                return searchRotated(nums, target, si, mid-1);
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        return searchRotated(nums, target, 0, nums.size()-1);
    }
};