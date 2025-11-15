class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1e9 + 7;

        vector<long long> full(n+1), half(n+1);

        full[0] = 1;
        full[1] = 1;

        half[0] = 0;
        half[1] = 0;

        for(int i=2; i<=n; i++) {
            full[i] = (full[i-1] + full[i-2] + 2 * half[i-1]) % MOD;
            half[i] = (half[i-1] + full[i-2]) % MOD;
        }

        return (int)full[n];
    }
};