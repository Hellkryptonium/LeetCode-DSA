class Solution {
 public:
  bool checkOnesSegment(string s) {
    bool isZero = false;
    for(char c : s) {
        if(c == '0') isZero = true;
        if(c == '1' && isZero) return false;
    }
    return true;
  }
};