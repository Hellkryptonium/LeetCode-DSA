class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int count[26] = {0};
        for(char ch : s) count[ch-'a']++;

        for(int i=0; i<s.length(); i++) {
            if(count[t[i] - 'a'] == 0) return false;

            count[t[i]-'a']--;
        }
        return true;
    }
};