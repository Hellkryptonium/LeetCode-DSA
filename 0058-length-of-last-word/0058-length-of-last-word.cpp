class Solution {
public:
    int lengthOfLastWord(string s) {
        auto end = find_if(s.rbegin(), s.rend(), [](char c) {return c != ' ';});
        auto start = find_if(end, s.rend(), [](char c) {return c == ' ';});
        return distance(end, start);
    }
};