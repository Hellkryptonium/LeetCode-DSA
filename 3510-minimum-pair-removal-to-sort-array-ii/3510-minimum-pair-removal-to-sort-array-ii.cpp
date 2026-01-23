#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        vector<long long> val(n);
        for (int i = 0; i < n; i++) val[i] = nums[i];

        // doubly linked list using indices
        vector<int> L(n), R(n);
        vector<char> alive(n, 1);
        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = (i + 1 < n ? i + 1 : -1);
        }

        auto badEdge = [&](int a, int b) -> bool {
            return a != -1 && b != -1 && alive[a] && alive[b] && val[a] > val[b];
        };

        int bad = 0;
        for (int i = 0; i + 1 < n; i++) if (val[i] > val[i + 1]) bad++;
        if (bad == 0) return 0;

        // min-heap of (sum, leftIndex)
        using Item = pair<long long,int>;
        priority_queue<Item, vector<Item>, greater<Item>> pq;
        for (int i = 0; i + 1 < n; i++) pq.push({val[i] + val[i + 1], i});

        auto validPair = [&](int i) -> bool {
            return i != -1 && alive[i] && R[i] != -1 && alive[R[i]];
        };

        int ops = 0, aliveCount = n;

        while (aliveCount > 1) {
            // pop until valid + up-to-date
            auto it = pq.top(); pq.pop();
            while (!validPair(it.second) || val[it.second] + val[R[it.second]] != it.first) {
                it = pq.top(); pq.pop();
            }

            int x = it.second;
            int y = R[x];
            int a = L[x];
            int b = R[y];

            // remove old bad contributions: (a,x), (x,y), (y,b)
            if (badEdge(a, x)) bad--;
            if (badEdge(x, y)) bad--;
            if (badEdge(y, b)) bad--;

            // merge y into x
            val[x] += val[y];
            alive[y] = 0;
            aliveCount--;
            ops++;

            // relink: x -> b
            R[x] = b;
            if (b != -1) L[b] = x;

            // add new bad contributions: (a,x), (x,b)
            if (badEdge(a, x)) bad++;
            if (badEdge(x, b)) bad++;

            // push new adjacent pairs involving x
            if (a != -1) pq.push({val[a] + val[x], a});
            if (b != -1) pq.push({val[x] + val[b], x});

            if (bad == 0) return ops;
        }

        return ops;
    }
};
