class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string current;
        backtrack(digits, 0, phone, current, result);
        return result;
    }
private:
    void backtrack(string& digits, int index, unordered_map<char, string>& phone, string& current, vector<string>& result) {

        if(index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index]];
        for(char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index+1, phone, current, result);
            current.pop_back();
        }
    }

};