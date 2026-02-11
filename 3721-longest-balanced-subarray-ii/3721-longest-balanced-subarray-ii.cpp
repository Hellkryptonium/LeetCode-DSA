#include <bits/stdc++.h>
using namespace std;

class SegTree {
public:
    int n;
    vector<int> mn, mx, lazy;

    SegTree(int n) : n(n) {
        int size = 4 * (n + 1);
        mn.assign(size, 0);
        mx.assign(size, 0);
        lazy.assign(size, 0);
        build(1, 0, n);
    }

    void build(int u, int l, int r) {
        mn[u] = mx[u] = lazy[u] = 0;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(u << 1, l, m);
        build(u << 1 | 1, m + 1, r);
    }

    void apply(int u, int delta) {
        mn[u] += delta;
        mx[u] += delta;
        lazy[u] += delta;
    }

    void push(int u) {
        if (lazy[u] != 0) {
            int d = lazy[u];
            apply(u << 1, d);
            apply(u << 1 | 1, d);
            lazy[u] = 0;
        }
    }

    void add_range(int ql, int qr, int delta) {
        add(1, 0, n, ql, qr, delta);
    }

    void add(int u, int l, int r, int ql, int qr, int delta) {
        if (ql <= l && r <= qr) {
            apply(u, delta);
            return;
        }
        push(u);
        int m = (l + r) >> 1;
        if (ql <= m) add(u << 1, l, m, ql, qr, delta);
        if (qr > m) add(u << 1 | 1, m + 1, r, ql, qr, delta);
        mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
        mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
    }

    int find_first_equal(int target) {
        return find(1, 0, n, target);
    }

    int find(int u, int l, int r, int target) {
        if (l == r) return l;
        push(u);
        int m = (l + r) >> 1;
        int left = u << 1;
        int right = u << 1 | 1;
        if (mn[left] <= target && target <= mx[left]) {
            return find(left, l, m, target);
        }
        return find(right, m + 1, r, target);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegTree st(n);

        unordered_map<int, int> last;  // value -> last index (1-based)
        int now = 0;                   // sum of (+1 odd, -1 even) over DISTINCT values
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int det = (x & 1) ? 1 : -1;

            if (!last.count(x)) {
                now += det;
            } else {
                st.add_range(last[x], n, -det);
            }

            last[x] = i;
            st.add_range(i, n, det);

            int j = st.find_first_equal(now);
            ans = max(ans, i - j);
        }

        return ans;
    }
};
