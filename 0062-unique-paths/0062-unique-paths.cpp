class Solution {
public:
    int uniquePaths(int m, int n) {
        long long N = m+n-2;
        long long R = min(m-1, n-1);

        long long ans = 1;

        for(long long i = 1; i<=R; i++) {
            ans = ans * (N-R+i) / i;
        }

        return (int)ans;
    }
};