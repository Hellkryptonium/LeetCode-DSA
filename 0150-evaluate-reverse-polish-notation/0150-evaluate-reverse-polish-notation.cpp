class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; //stack to hold operands (number)

        for(string& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                //Pop top 2 numbers
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int result = 0;
                if(token == "+") result = a + b;
                else if(token == "-") result = a - b;
                else if(token == "*") result = a * b;
                else if(token == "/") result = a / b;

                st.push(result);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top(); // final result
    }
};