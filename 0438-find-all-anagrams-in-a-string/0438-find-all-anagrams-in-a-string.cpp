class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.length();
        int k = p.length();

        if(k > n) return {};

        vector<int> freqP(26, 0);
        vector<int> freqW(26, 0);

        for(int i=0; i<k; i++) {
            freqP[p[i] - 'a']++;
            freqW[s[i] - 'a']++;
        }

        if(freqP == freqW) result.push_back(0);

        for(int i=k; i<n; i++) {
            freqW[s[i-k] - 'a']--;
            freqW[s[i] - 'a']++;

            if(freqP == freqW) result.push_back(i-k+1);
        }

        return result;
    }
};