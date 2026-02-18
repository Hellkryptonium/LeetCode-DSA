class Solution {
public:
    string binary (int n) {
        string s = "";

        while(n > 0) {
            int bit = n % 2;
            s.push_back('0' + bit);
            n /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
    bool hasAlternatingBits(int n) {
        string s = binary(n);
        for(int i=1; i<s.size(); i++) {
            if(s[i-1] == s[i]) {
                return false;
            }
        }
        return true;
    }
};