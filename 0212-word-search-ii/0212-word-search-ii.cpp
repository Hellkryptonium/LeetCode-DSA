class TrieNode {
public: 
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }

};

class Solution {
public:
    vector<string> result;
    TrieNode* root = new TrieNode();

    void insertWord(const string& word) {
        TrieNode* node = root;
        for(char c : word) {
            int idx = c-'a';
            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node=node->children[idx];
        }
        node->isEnd = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if(i < 0 || j < 0 || i >= board.size() || j>= board[0].size()) {
            return;
        }

        char c = board[i][j];
        if(c == '#') return;

        TrieNode* next = node->children[c-'a'];
        if(next == nullptr) return;

        if(next->isEnd) {
            result.push_back(next->word);
            next->isEnd = false;
        }

        board[i][j] = '#';

        dfs(board, i+1, j, next);
        dfs(board, i-1, j, next);
        dfs(board, i, j+1, next);
        dfs(board, i, j-1, next);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const string& word : words) {
            insertWord(word);
        }

        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dfs(board, i, j, root);
            }
        }
        
        return result;
    }
};