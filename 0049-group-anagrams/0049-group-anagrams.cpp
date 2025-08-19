class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        buckets.reserve(strs.size());

        for(const string& s : strs) {

            int freq[26] = {0};
            for(char c : s) freq[c - 'a']++;

            string key;
            key.reserve(26*3);
            for(int i=0; i<26; ++i) {
                key.push_back('#');
                key += to_string(freq[i]);
            }

            buckets[key].push_back(s);
        }
        vector<vector<string>> ans;
        ans.reserve(buckets.size());
        for(unordered_map<string, vector<string>>::value_type &kv : buckets) ans.push_back(move(kv.second));
        return ans;
    }
};