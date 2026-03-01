class Solution {
public:
    void pathHelper(int src, int dest, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans)
    {
        path.push_back(src);

        // reached destination
        if (src == dest) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (int v : graph[src]) {
            pathHelper(v, dest, graph, path, ans);
        }

        // backtracking
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;

        pathHelper(0, n - 1, graph, path, ans);

        return ans;
    }
};