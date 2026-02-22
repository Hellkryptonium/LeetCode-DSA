class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result;
        for(int i=0; i<n; i++) {
            int ans = 0;
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if(boxes[j] == '1') {
                    ans += abs(j-i);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};