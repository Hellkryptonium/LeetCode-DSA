class Solution {
public:
    int singleNumber(vector<int>& a) {
        unordered_map<int, int> freq;
        freq.reserve(a.size());

        for (int x : a)
        freq[x]++;

        for (int x : a)
        {
            if (freq[x] == 1)
            {
                return x;
                break;
            }
        }
        return -1;
    }
};