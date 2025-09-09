class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;

        for(int i=0; i < s.length(); i++) {
            char c = s[i];

            if(isdigit(c)) {
                int num = 0;
                while(i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += sign * num;
            }
            else if(c == '+') {
                sign = 1;
            } else if(c == '-') {
                sign = -1;
            } else if(c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')') {
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            } else if(c == ' ') {
                continue;
            }
        }
        return result;
    }
};