class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(ch >= 'A' && ch <= 'Z') {
                s[i] = ch - 'A' + 'a';
            } 
        }
        return s;
    }
};