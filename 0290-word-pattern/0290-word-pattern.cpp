class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while(iss >> word) {
            words.push_back(word);
        }

        if(pattern.size() != words.size()) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        for(int i=0; i<pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            //pattern to word
            if(p2w.count(c)) {
                if(p2w[c] != w) return false;
            } else {
                p2w[c] = w;
            }

            if(w2p.count(w)) {
                if(w2p[w] != c) return false;
            } else {
                w2p[w] = c;
            }
        }

        return true;
    }
};