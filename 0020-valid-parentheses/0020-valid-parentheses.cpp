class Solution {
public:
    bool isValid(string s) {
       string temp = "";

       for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            temp += c;
        } else {
            if(temp.empty()) return false;

            char last = temp.back();
            if((c == ')' && last == '(') ||
                (c == '}' && last == '{')  ||
                (c == ']' && last == '[')) {
                    temp.pop_back();
            } else {
                return false;
            }

        }
       } 
       return temp.empty();
    }
};