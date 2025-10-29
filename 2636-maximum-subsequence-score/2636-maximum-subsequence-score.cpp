class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);

        for(int i=0; i<n; i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0, maxScore = 0;

        for(auto& [num2, num1] : pairs) {
            sum += num1;
            minHeap.push(num1);

            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k) {
                long long score = sum * num2;
                maxScore = max(maxScore, score);
            }
        }
        return maxScore;
    }
};