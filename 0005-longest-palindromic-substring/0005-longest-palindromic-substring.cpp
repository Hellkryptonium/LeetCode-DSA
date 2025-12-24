class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while(i<j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPalindrome(s, i, j)) {
                    if(j-i+1 > ans.length()) {
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};