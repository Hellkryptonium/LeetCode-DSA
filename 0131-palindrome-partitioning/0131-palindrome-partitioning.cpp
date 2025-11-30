class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(0, s, path, result);
        return result;
    }

    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &result) {
        if(index == s.size()) {
            result.push_back(path);
            return;
        }

        for(int j=index; j<s.length(); j++) {
            if(isPalindrome(s, index, j)) {
                path.push_back(s.substr(index, j-index+1));

                dfs(j+1, s, path, result);

                path.pop_back();
            } 
        }
    }

    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};