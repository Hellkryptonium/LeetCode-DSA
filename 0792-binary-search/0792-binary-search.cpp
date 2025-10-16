class Solution {
public:
    int bs(vector<int>& nums, int key, int st, int end) {
        if(st <= end) {
            int mid = st + (end-st)/2;
            if(nums[mid] == key) return mid;
            else if(nums[mid] <= key) {
                return bs(nums, key, mid+1, end);
            } else {
                return bs(nums, key, st, mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int key) {
        int st=0, end=nums.size()-1;
        return bs(nums, key, st, end);
    }
};