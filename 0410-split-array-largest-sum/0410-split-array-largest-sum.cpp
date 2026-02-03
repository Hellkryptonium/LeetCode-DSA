class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;

        for(int x : nums) {
            left = max(left, x);
            right += x;
        }

        int answer = right;

        while(left <= right) {
            int mid = left + (right - left)/2;

            int subarrays = 1;
            int currentSum = 0;

            for(int x : nums) {
                if(currentSum + x <= mid) {
                    currentSum += x;
                } else {
                    subarrays++;
                    currentSum = x;
                }
            }

            if(subarrays  <= k) {
                answer = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return answer;
    }
};