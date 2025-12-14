class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;

        int maxLen = 0;
        for(auto& w : words) {
            maxLen = max(maxLen, (int)w.length());
        }

        for(int i=1; i<=n; i++) {
            for(int j=max(0, i-maxLen); j<i; j++) {
                if(dp[j] && words.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};