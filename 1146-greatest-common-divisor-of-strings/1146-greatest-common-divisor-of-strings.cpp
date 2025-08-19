class Solution {
public:
    bool divides(const string &s, const string &t) {
        if(s.length() % t.length() != 0) return false;
        int repeat = s.length() / t.length();
        string temp = "";
        for(int i=0; i<repeat; i++) {
            temp += t;
        }
        return temp == s;
    }

    string gcdOfStrings(string str1, string str2) {
        int lenGCD = gcd(str1.length(), str2.length());
        string candidate = str1.substr(0, lenGCD);
        if(divides(str1, candidate) && divides(str2, candidate)) {
            return candidate;
        } else {
            return "";
        }
    }
};