class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<tuple<int, int, int>>q;
        int er = entrance[0], ec = entrance[1];
        q.push({er, ec, 0});
        maze[er][ec] = '+';

        vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

        while(!q.empty()) {
            auto[r, c, steps] = q.front(); q.pop();

            for(auto[dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                    if((nr == 0 || nr == rows-1 || nc == 0 || nc == cols-1) && !(nr==er && nc==ec)) {
                        return steps+1;
                    }

                    maze[nr][nc] = '+';
                    q.push({nr, nc, steps+1});
                }
            }
        }
        return -1;
    }
};