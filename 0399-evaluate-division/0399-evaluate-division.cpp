class Solution {
public:
    double dfs(const string& curr, const string& target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
        if(graph.find(curr) == graph.end()) return -1.0;
        if(curr == target) return 1.0;

        visited.insert(curr);

        for(auto& neighborPair : graph[curr]) {
            const string& neighbor = neighborPair.first;
            const double& weight = neighborPair.second;

            if(!visited.count(neighbor)) {
                double res = dfs(neighbor, target, graph, visited);
                if(res != -1.0) {
                    return res * weight;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for(int i=0; i<equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A].emplace_back(B, val);
            graph[B].emplace_back(A, 1.0/val);
        }

        vector<double> result;
        for(auto& q : queries) {
            const string& start = q[0];
            const string& end = q[1];
            unordered_set<string> visited;
            result.push_back(dfs(start, end, graph, visited));
        }

        return result;
    }
};