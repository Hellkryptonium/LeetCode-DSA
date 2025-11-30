class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for(int num : nums) {
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin+num);
            minSum = min(minSum, currMin);

            totalSum += num;
        }

        if(maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum-minSum);
    }
};