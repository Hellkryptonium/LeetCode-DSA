class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        queue<int> q;

        for(int i=0; i<s.size(); i++) {
            q.push(i);
            freq[s[i] - 'a']++;

            while(!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                q.pop();
            }
        }

        return ((q.empty()) ? -1 : q.front());
    }
};