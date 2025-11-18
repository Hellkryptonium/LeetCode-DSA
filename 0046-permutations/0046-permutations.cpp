class Solution {
private: 
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& ans) {
        if(path.size() == nums.size()) {
            ans.push_back(path);
        }

        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, path, used, ans);

            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtrack(nums, path, used, ans);

        return ans;
    }
};