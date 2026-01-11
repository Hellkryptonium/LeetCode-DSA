class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string dir;
        while(getline(ss, dir, '/')) {
            if(dir == "" || dir == ".") continue;
            if(dir == "..") {
                if(!st.empty()) st.pop_back();
            } else {
                st.push_back(dir);
            }
        }

        string result = "/";
        for(int i=0; i<st.size(); i++) {
            result += st[i];
            if(i != st.size()-1) result+="/";
        }

        return result;
    }
};