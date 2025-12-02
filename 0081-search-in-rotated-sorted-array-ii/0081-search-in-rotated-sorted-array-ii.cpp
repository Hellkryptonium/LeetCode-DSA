class Solution {
private:
    bool searchRotated(vector<int>& nums, int si, int ei, int target) {
        if (si > ei) return false;

        int mid = si + (ei - si) / 2;
        if (nums[mid] == target) return true;
        
        if (nums[si] == nums[mid] && nums[mid] == nums[ei]) {
            // shrink both ends
            return searchRotated(nums, si + 1, ei - 1, target);
        }

        // Left half is sorted
        if (nums[si] <= nums[mid]) {
            if (nums[si] <= target && target <= nums[mid]) {
                return searchRotated(nums, si, mid - 1, target);
            } else {
                return searchRotated(nums, mid + 1, ei, target);
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] <= target && target <= nums[ei]) {
                return searchRotated(nums, mid + 1, ei, target);
            } else {
                return searchRotated(nums, si, mid - 1, target);
            }
        }
    }
public:
    bool search(vector<int>& nums, int target) {
        return searchRotated(nums, 0, nums.size() - 1, target);
    }
};
