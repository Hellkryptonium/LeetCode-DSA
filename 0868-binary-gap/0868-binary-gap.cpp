class Solution {
public:
    string binary(int n) {
        string s = "";
        while(n > 0) {
            int bit = n % 2;
            s.push_back('0'+bit);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int binaryGap(int n) {
        string s = binary(n);
        cout << s;
        int ans = 0;
        int last = -1;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {
                if(last != -1) {
                    ans = max(ans, i-last);
                }
                last = i;
            }
        }
        return ans;
    }
};