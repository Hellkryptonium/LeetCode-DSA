class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while(n) {
            n = n & (n-1);
            count++;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int num=left; num<=right; num++) {
            int count = countBits(num);

            if(isPrime(count)) {
                ans++;
            }
        }
        return ans;
    }

    bool isPrime(int n) {
        if(n<2) return false;
        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
};