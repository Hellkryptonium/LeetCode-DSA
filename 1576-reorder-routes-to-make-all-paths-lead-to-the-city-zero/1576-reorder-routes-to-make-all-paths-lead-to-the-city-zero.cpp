class Solution {
public:
    int res = 0;

    void dfs(int node, vector<vector<int>>& graph, set<pair<int,int>>& edges, vector<bool>& visited) {
        visited[node] = true;

        for(int nei : graph[node]) {
            if(!visited[nei]) {
                if(edges.find({node, nei}) != edges.end()) {
                    res++;
                }
                dfs(nei, graph, edges, visited);
            }
        }
    }


    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        set<pair<int,int>> edges;

        for(auto conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            edges.insert({a, b});
        }

        vector<bool> visited(n, false);
        dfs(0, graph, edges, visited);

        return res;
    }
};