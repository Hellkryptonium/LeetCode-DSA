class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> freq;

        // count frequency
        for(int n : nums)
            freq[n]++;

        // custom sorting
        sort(nums.begin(), nums.end(),
            [&](int a, int b) {

                if(freq[a] == freq[b])
                    return a > b;     // larger first

                return freq[a] < freq[b]; // smaller freq first
            });

        return nums;
    }
};