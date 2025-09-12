class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r = s.length()-1;

        while(l < r) {
            if(isalnum(s[l])) {
                if(isalnum(s[r])) {
                    if(tolower(s[l++]) != tolower(s[r--])) return false;
                } else r--;
            } else l++;
        }
        return true;
    }
};