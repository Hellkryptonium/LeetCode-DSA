#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        int cost, x, y, t;
        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        // Sort cells by value
        vector<array<int,3>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});
        sort(cells.begin(), cells.end());

        // teleport pointer per teleport count
        vector<int> teleportPtr(k + 1, 0);

        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [cost, x, y, t] = pq.top();
            pq.pop();

            if (cost > dist[x][y][t]) continue;

            if (x == m - 1 && y == n - 1)
                return cost;

            // Normal moves
            if (x + 1 < m) {
                int nc = cost + grid[x + 1][y];
                if (nc < dist[x + 1][y][t]) {
                    dist[x + 1][y][t] = nc;
                    pq.push({nc, x + 1, y, t});
                }
            }

            if (y + 1 < n) {
                int nc = cost + grid[x][y + 1];
                if (nc < dist[x][y + 1][t]) {
                    dist[x][y + 1][t] = nc;
                    pq.push({nc, x, y + 1, t});
                }
            }

            // Teleport (OPTIMIZED)
            if (t < k) {
                int &ptr = teleportPtr[t];
                while (ptr < cells.size() && cells[ptr][0] <= grid[x][y]) {
                    int nx = cells[ptr][1];
                    int ny = cells[ptr][2];
                    if (cost < dist[nx][ny][t + 1]) {
                        dist[nx][ny][t + 1] = cost;
                        pq.push({cost, nx, ny, t + 1});
                    }
                    ptr++;
                }
            }
        }

        return -1;
    }
};
