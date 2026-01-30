#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long INF = 4e18;

    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        int n = source.size();
        int m = original.size();

        // Map each unique string to an id
        unordered_map<string, int> id;
        vector<string> all;

        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = all.size();
                all.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < m; i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int K = all.size();

        // Floyd–Warshall graph
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < K; k++) {
            for (int i = 0; i < K; i++) {
                if (dist[i][k] >= INF) continue;
                for (int j = 0; j < K; j++) {
                    if (dist[k][j] >= INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Group transformations by length
        unordered_map<int, vector<pair<int,int>>> byLen;
        for (int i = 0; i < m; i++) {
            byLen[original[i].size()].push_back({
                id[original[i]], id[changed[i]]
            });
        }

        // DP
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Single character case
            if (source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }

            for (auto& [len, vec] : byLen) {
                if (i + len > n) continue;

                // Fast equal check
                if (source.compare(i, len, target, i, len) == 0) {
                    dp[i] = min(dp[i], dp[i + len]);
                    continue;
                }

                string s1 = source.substr(i, len);
                string s2 = target.substr(i, len);

                if (!id.count(s1) || !id.count(s2)) continue;

                long long c = dist[id[s1]][id[s2]];
                if (c < INF) {
                    dp[i] = min(dp[i], c + dp[i + len]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};
