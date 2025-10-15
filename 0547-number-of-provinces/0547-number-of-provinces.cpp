class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       int provinceCount = 0;
       vector<bool> visited(n, false);

       function<void(int)> dfs = [&](int city) -> void {
        visited[city] = true;

        for(int neighbor = 0; neighbor < n; neighbor++) {
            if(!visited[neighbor] && isConnected[city][neighbor] == 1) {
                dfs(neighbor);
            }
        }
       };

       for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i);
            provinceCount++;
        }
       }

       return provinceCount;
    }
};