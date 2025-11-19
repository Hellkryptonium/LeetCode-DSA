class Solution {
private: 
    void backtrack(int i, int target, vector<int>& path, vector<int>& candidates, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }
        if(target < 0) return;
        if(i == candidates.size()) return;

        path.push_back(candidates[i]);
        backtrack(i, target-candidates[i], path, candidates, ans);
        path.pop_back();

        backtrack(i+1, target, path, candidates, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        backtrack(0, target, path, candidates, ans);
        return ans;
    }
};