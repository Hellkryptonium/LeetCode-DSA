class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()) return false;

        char diffChar1, diffChar2;
        int diff = 0;

        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) {
                if(diff == 0) {
                    diffChar1 = s1[i];
                    diffChar2 = s2[i];
                } else if(diff == 1) {
                    if(s1[i] != diffChar2 || s2[i] != diffChar1) {
                        return false;
                    }
                } else {
                    return false;
                }
                diff++;
            }
        }
        return diff==0 || diff==2;
    }
};