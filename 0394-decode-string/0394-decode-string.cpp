class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;
        int currNum = 0;
        string currStr = "";

        for(char c : s) {
            if(isdigit(c)) {
                currNum = currNum * 10 + (c-'0');
            } else if (c == '['){
                numSt.push(currNum);
                strSt.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatTimes = numSt.top(); numSt.pop();
                string prevStr = strSt.top(); strSt.pop();
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