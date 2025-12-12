class Solution {
public:
    bool palin(string s) {
        int l = 0, r = s.size()-1;
        while(l<=r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        string n = to_string(x);

        return palin(n);
    }
};