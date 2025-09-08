class Solution {
public:
    int search(vector<int>& nums, int key) {
        int st=0, end = nums.size()-1;
        while(st<=end) {
            int mid = st+(end-st)/2;
            if(nums[mid] == key) return mid;
            else if(nums[mid] <= key) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};