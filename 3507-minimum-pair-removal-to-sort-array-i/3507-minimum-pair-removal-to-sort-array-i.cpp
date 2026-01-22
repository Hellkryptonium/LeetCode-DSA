class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int minSum = INT_MAX;
        int index = 0;

        for(int i=0; i+1<nums.size(); i++) {
            int s = nums[i] + nums[i+1];
            if(s < minSum) {
                minSum = s;
                index = i;
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
       int operans = 0;

       while(!is_sorted(begin(nums), end(nums))) {
        int index = minPairSum(nums);

        nums[index] = nums[index] + nums[index+1];

        nums.erase(begin(nums) + index + 1);

        operans++;
       } 
        return operans;
    }
};