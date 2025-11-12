class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;
        
        unordered_map<string, vector<string>> patternMap;
        for(string word : wordList) {
            for(int i=0; i<word.length(); i++) {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()) {
            auto[word, level] = q.front();
            q.pop();

            if(word == endWord) return level;

            for(int i=0; i<word.length(); i++) {
                string pattern = word;
                pattern[i] = '*';

                for(string neighbor : patternMap[pattern]) {
                    if(!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push({neighbor, level+1});
                    }
                }
            }
        }

        return 0;
    }
};