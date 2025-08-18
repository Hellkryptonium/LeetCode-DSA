class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> freq;

        for(char c : s) freq[c]++;
        for(char c : t) freq[c]--;
        for(pair<const char, int> &p : freq) {
            if(p.second != 0) return false;
        }
        return true;
    }
};