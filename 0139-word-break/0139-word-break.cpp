class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for(char c : word) {
            if(!temp->children.count(c))
                temp->children[c] = new Node();
            temp = temp->children[c];
        }
        temp->endOfWord = true;
    }
};

class Solution {
public:
    bool helper(string &s, int index,
                Trie &trie,
                vector<int> &dp) {

        if(index == s.size())
            return true;

        if(dp[index] != -1)
            return dp[index];

        Node* temp = trie.root;

        for(int i = index; i < s.size(); i++) {

            if(!temp->children.count(s[i]))
                break;

            temp = temp->children[s[i]];

            if(temp->endOfWord &&
               helper(s, i + 1, trie, dp)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s,
                   vector<string>& wordDict) {

        Trie trie;
        for(auto &w : wordDict)
            trie.insert(w);

        vector<int> dp(s.size(), -1);

        return helper(s, 0, trie, dp);
    }
};