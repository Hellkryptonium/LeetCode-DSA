class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int score = nums[0];
        int first = INT_MAX;
        int second = INT_MAX;
        for(int i=1; i<n; i++) {
            if(nums[i] < first) {
                second = first;
                first = nums[i];
            } else if(nums[i] < second){
                second = nums[i];
            }
        }

        return score + first + second;
    }
};