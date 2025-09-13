class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int n : arr) {
            freq[n]++;
        }

        unordered_set<int> counts;
        for(auto& it : freq) {
            counts.insert(it.second);
        }

        return freq.size() == counts.size();
    }
};