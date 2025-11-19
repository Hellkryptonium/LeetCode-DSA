class Solution {
private: 
    int searchRotated(vector<int>& nums, int si, int ei, int target) {
        if(si > ei) {
            return -1;
        }

        int mid = si + (ei - si) / 2;
        if(nums[mid] == target) return mid;
        if(nums[si] <= nums[mid]) {//L1
            if(nums[si] <= target && target <= nums[mid]) { // left
                return searchRotated(nums, si, mid-1, target);
            } else { // right
                return searchRotated(nums, mid+1, ei, target);
            }
        } else {//L2
            if(nums[mid] <= target && target <= nums[ei]) { //right
                return searchRotated(nums, mid+1, ei, target);
            } else { // left
                return searchRotated(nums, si, mid-1, target);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return searchRotated(nums, 0, nums.size()-1, target);
    }
};