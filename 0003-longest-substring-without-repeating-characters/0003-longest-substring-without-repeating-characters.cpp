class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int start = 0;
        int maxLength = 0;

        for(int end=0; end < s.length(); end++) {
            char currentChar = s[end];

            if(charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = end;

            int windowLength = end - start + 1;
            if(windowLength > maxLength) {
                maxLength = windowLength;
            }
        }
        return maxLength;
    }
};