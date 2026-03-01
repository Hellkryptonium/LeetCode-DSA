class Solution {
public:
    bool dfs(int src, int dest, vector<bool>& vis, vector<vector<int>>& edges) {
        if(src == dest) return true;

        vis[src] = true;

        vector<int> neighbors = edges[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(dfs(v, dest, vis, edges)) {
                    return true;
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // undirected graph
        }

        return dfs(source, destination, vis, adj);
    }
};