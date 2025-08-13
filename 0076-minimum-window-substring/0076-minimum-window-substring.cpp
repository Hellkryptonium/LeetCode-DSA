class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> need;
        for(char c : t) need[c]++;

        unordered_map<char, int> have;
        int matches = 0;
        int required = need.size();
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right=0; right < s.size(); right++) {
            char c = s[right];
            have[c]++;

            if(need.count(c) && have[c] == need[c]) {
                matches++;
            }

            while(matches == required) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char d = s[left];
                have[d]--;

                if(need.count(d) && have[d] < need[d]) {
                    matches--;
                }

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};