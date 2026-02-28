class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        
        for(int num=1; num<=n; num++) {
            int digits = log2(num) + 1;

            result = ((result << digits)%M + num)%M;
        }

        return result;
    }
};