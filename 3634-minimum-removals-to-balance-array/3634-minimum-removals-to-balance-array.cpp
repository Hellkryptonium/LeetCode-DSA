class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long i=0, j=0;
        long long n = nums.size();
        long long L = 1;
        long long maxEl = nums[0], minEl = nums[0];
        while(j<n) {
           minEl = nums[i];
           maxEl = nums[j];

           while(i < j && maxEl > (k * minEl)) {
            i++;
            minEl = nums[i];
           }

           L = max(L, j-i+1);
           j++;
        }
        return n-L;
    }
};