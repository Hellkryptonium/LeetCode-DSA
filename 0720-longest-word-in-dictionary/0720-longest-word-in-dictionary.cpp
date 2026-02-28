#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // Insert word into trie
    void insert(string key)
    {
        Node *temp = root;

        for (char ch : key)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }

        temp->endOfWord = true;
    }

    // Check if all prefixes exist
    bool checkAllPrefixes(string key)
    {
        Node *temp = root;

        for (char ch : key)
        {
            if (temp->children.count(ch) == 0)
                return false;

            temp = temp->children[ch];

            // every prefix must be a word
            if (!temp->endOfWord)
                return false;
        }

        return true;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie trie;

        // Step 1: Insert all words
        for (string &word : words)
        {
            trie.insert(word);
        }

        string ans = "";

        // Step 2: Check valid words
        for (string &word : words)
        {
            if (trie.checkAllPrefixes(word))
            {
                if (word.length() > ans.length() ||
                    (word.length() == ans.length() && word < ans))
                {
                    ans = word;
                }
            }
        }

        return ans;
    }
};