class Solution {
public:
    int minOperations(string s) {
        int cost10 = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] - '0' == i%2) {
                cost10++;
            }
        }

        cout << cost10;

        int cost01 = s.length() - cost10;
        return min(cost01, cost10);
    }
};