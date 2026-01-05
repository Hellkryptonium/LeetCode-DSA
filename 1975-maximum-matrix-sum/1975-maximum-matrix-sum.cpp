class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int count = 0;
        int minv = INT_MAX;

        for(const auto& row : matrix) {
            for(int value : row) {
                if(value < 0) {
                    count++;
                }

                int absValue = abs(value);
                minv = min(minv, absValue);
                sum += absValue;
                cout << sum;
            }
        }

        if(count % 2 == 0) {
            return sum;
        }

        return sum - 2 * minv;
    }
};