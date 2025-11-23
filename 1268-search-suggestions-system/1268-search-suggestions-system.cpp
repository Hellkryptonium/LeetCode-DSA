class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        vector<string> suggestions;

        TrieNode() {
            for(int i=0; i<26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c - 'a';

            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];

            if(curr->suggestions.size() < 3) {
                curr->suggestions.push_back(word);
            }
        }
    }

    vector<vector<string>> getSuggestions(TrieNode* root, const string& searchWord) {
        vector<vector<string>> result;
        TrieNode* curr = root;

        for(char c : searchWord) {
            int idx = c - 'a';

            if(curr && curr->children[idx]) {
                curr = curr->children[idx];
                result.push_back(curr->suggestions);
            } else {
                curr = nullptr;
                result.push_back({});
            }
        }
        return result;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        TrieNode* root = new TrieNode();
        for(string &p : products) {
            insert(root, p);
        }

        return getSuggestions(root, searchWord);
    }
};