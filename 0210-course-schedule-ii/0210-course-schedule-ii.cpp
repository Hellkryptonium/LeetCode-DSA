class Solution {
public:

    bool isCycle(int src,
                 vector<vector<int>>& adj,
                 vector<bool>& vis,
                 vector<bool>& rec)
    {
        vis[src] = true;
        rec[src] = true;

        for (int v : adj[src]) {

            if (!vis[v]) {
                if (isCycle(v, adj, vis, rec))
                    return true;
            }
            else if (rec[v]) {
                return true;
            }
        }

        rec[src] = false;   // backtrack
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int>& s, vector<vector<int>>& graph) {
        vis[src] = true;

        for(int i=0; i<graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src) {
                if(!vis[v]) {
                    topoSort(v, vis, s, graph);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(numCourses);

        // build graph
        for (auto &e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, adj, vis, rec))
                    return ans;
            }
        }

        //topological sortingvis
        vector<bool> vis2(V, false);
        stack<int> s;
        for(int i=0; i<V; i++) {
            if(!vis2[i]) {
                topoSort(i, vis2, s, prerequisites);
            }
        }

        while(s.size() > 0) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};