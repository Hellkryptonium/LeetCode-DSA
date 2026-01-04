class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int num : nums) {
            int count=0, sum=0;
            for(int i=1; i<=num; i++) {
                if(num % i == 0) {
                    sum += i;
                    count++;
                }
                if(count > 4) break;
            }
            if(count == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};