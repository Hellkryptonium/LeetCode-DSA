class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> st;
        while(ss >> word) {
            st.push(word);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if(st.empty() == false) {
                ans += " ";
            }
        }
        return ans;
    }
};