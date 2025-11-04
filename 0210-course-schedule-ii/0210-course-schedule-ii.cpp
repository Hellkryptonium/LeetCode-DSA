class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> order;
        bool hasCycle = false;

        function<void(int)> dfs = [&](int node) {
            if(hasCycle) return;
            visited[node] = 1;

            for(int next : adj[node]) {
                if(visited[next] == 0) {
                    dfs(next);
                } else if(visited[next] == 1) {
                    hasCycle = true;
                }
            }

            visited[node] = 2;
            order.push_back(node);
        };

        for(int i=0; i<numCourses; i++) {
            if(visited[i] == 0) {
                dfs(i);
            }
        }

        if(hasCycle) return {};
        reverse(order.begin(), order.end());

        return order;
    }
};