class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCountTotal = words.size();
        int totalLen = wordLen * wordCountTotal;

        if(s.size() < totalLen) return result;

        unordered_map<string, int> wordCount;
        for(auto &w : words) wordCount[w]++;

        for(int offset = 0; offset < wordLen; offset++) {
            int left = offset, right = offset;
            unordered_map<string, int> seen;
            int count = 0;

            while(right + wordLen <= (int)s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if(wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    while(seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left,wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == wordCountTotal) {
                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};