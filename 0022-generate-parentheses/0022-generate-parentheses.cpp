class Solution {
    vector<string> ans;
private:
    void dfs(int left, int right, string curr, int n) {
        if(left>n || right > n || left < right) return;

        if(left == n && right == n) {
            ans.push_back(curr);
        }
        if(left < n) {
            dfs(left+1, right, curr+"(", n);
        }

        if(right < n) {
            dfs(left, right+1, curr+")", n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, "", n);

        return ans;
    }
};