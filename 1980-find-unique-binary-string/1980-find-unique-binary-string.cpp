class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int bitSize = nums[0].size();
        int maxNum = 1 << bitSize;
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(stoi(nums[i], nullptr, 2));
        }

        for(int i=0; i<maxNum; i++) {
            if(!s.contains(i)) {
                return std::bitset<16>(i).to_string().substr(16-bitSize);
            }
        }

        throw;
    }
};