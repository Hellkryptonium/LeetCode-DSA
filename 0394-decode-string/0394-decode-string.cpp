class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;

        for(char c : s) {
            if(isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatTimes = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();

                string temp = "";
                for(int i=0; i<repeatTimes; i++) {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            } else {
                currStr += c;
            }
        }
        return currStr;
    }
};