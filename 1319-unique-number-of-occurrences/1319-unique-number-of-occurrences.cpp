class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int n : arr) {
            freq[n]++;
        }

        unordered_set<int> counts;
        for(auto& it : freq) {
            int freq = it.second;
            if(counts.find(freq) != counts.end()) {
                return false;
            }
            counts.insert(freq);
        }
        return true;
    }
};