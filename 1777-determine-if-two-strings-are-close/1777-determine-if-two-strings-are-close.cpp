class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        unordered_map<char, int> freq1, freq2;

        for(char c : word1) freq1[c]++;
        for(char c : word2) freq2[c]++;

        unordered_set<char> set1, set2;
        for(auto &p : freq1) set1.insert(p.first);
        for(auto &p : freq2) set2.insert(p.first);
        if(set1 != set2) return false;

        vector<int> counts1, counts2;
        for(auto &p : freq1) counts1.push_back(p.second);
        for(auto &p : freq2) counts2.push_back(p.second);
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};