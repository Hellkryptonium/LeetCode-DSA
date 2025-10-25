class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int minutes = 0;

        while(!q.empty() && fresh > 0) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                auto[x,y] = q.front();
                q.pop();

                for(auto &dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }    
                }
            }
            minutes++;
        }
        return (fresh==0) ? minutes : -1;
    }
};