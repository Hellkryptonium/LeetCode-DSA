class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        int count = 0, maxCount = 0;

        //first window
        for(int i=0; i<k; i++) {
            if(isVowel(s[i])) count++;
        }

        maxCount = count;

        //slide window
        for(int i=k; i<s.size(); i++) {
            if(isVowel(s[i])) count++;
            if(isVowel(s[i-k])) count--;

            maxCount = max(maxCount, count);

            if(maxCount == k) return k;
        }

        return maxCount;
    }
};