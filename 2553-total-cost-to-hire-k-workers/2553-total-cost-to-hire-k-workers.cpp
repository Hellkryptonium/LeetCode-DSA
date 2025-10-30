#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long total = 0;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> left, right;
        int i = 0, j = n - 1;

        for (; i < candidates && i <= j; i++)
            left.push({costs[i], i});

        for (int count = 0; count < candidates && j >= i; count++, j--)
            right.push({costs[j], j});

        for (int hired = 0; hired < k; hired++) {
            pair<int, int> pick;
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                pick = left.top();
                left.pop();
                total += pick.first;
                if (i <= j) left.push({costs[i], i++});
            } else {
                pick = right.top();
                right.pop();
                total += pick.first;
                if (i <= j) right.push({costs[j], j--});
            }
        }
        return total;
    }
};
