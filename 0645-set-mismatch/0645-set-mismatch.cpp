class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        vector<int> isPresent(n+1, false);

        for(int i=0; i<n; i++) {
            if(isPresent[nums[i]]) {
                ans.push_back(nums[i]);
            } else {
                isPresent[nums[i]] = true;
            }
        }

        for(int i=1; i<=n; i++) {
            if(!isPresent[i]) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};