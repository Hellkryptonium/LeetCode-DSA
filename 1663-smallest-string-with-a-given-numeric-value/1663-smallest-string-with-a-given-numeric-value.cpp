class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');

        int extra = k - n;

        for(int i=n-1; i>=0 && extra > 0; i--) {
            int add = min(25, extra);
            s[i] = char(s[i]+add);
            extra -= add;
        }

        return s;
    }
};