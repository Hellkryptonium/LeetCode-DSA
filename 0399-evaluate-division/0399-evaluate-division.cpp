class Solution {
public:
    double dfs(const string& curr, const string& target, unordered_map<string, vector<pair<string,double>>>& graph, unordered_set<string>& visited, double product) {
        if(graph.find(curr) == graph.end()) return -1.0;

        if(curr == target) return product;

        visited.insert(curr);

        for(auto& neighborPair : graph[curr]) {
            const string& neighbor = neighborPair.first;
            const double& weight = neighborPair.second;

            if(!visited.count(neighbor)) {
                double res = dfs(neighbor, target, graph, visited, product*weight);
                if(res != -1.0) {
                    return res;
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
            graph[B].emplace_back(A, 1/val);
        }

        vector<double> result;
        for(auto& q : queries) {
            const string& start = q[0];
            const string& end = q[1];

            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                result.push_back(-1.0);
            }

            else if(start == end) {
                result.push_back(1.0);
            }

            else {
                unordered_set<string> visited;
                double res = dfs(start, end, graph, visited, 1.0);
                result.push_back(res);
            }
        }
        return result;
    }
};