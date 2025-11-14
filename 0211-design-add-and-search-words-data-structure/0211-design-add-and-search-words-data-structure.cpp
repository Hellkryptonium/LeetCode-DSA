class WordDictionary {
private: 
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i=0; i<26; i++) {
                children[i] = nullptr; 
            }
        }
    };

    TrieNode* root;

    bool dfs(int index, TrieNode* node, string& word) {
        if(!node) return false;

        if(index == word.size()) return node->isEnd;

        char c = word[index];

        //case 1: normal character
        if(c != '.') {
            return dfs(index+1, node->children[c-'a'], word);
        }

        //case 2: dot try all 26 children

        for(int i=0; i<26; i++) {
            if(node->children[i] && dfs(index+1, node->children[i], word)) {
                return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c-'a';
            if(!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */