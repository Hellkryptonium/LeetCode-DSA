class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       int m = board.size();
       int n = board[0].size(); 

       vector<pair<int,int>> directions = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},          {0,1},
        {1,-1}, {1,0}, {1,1}
       };

       for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int live_neighbors = 0;

            for(auto dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if(board[ni][nj] == 1 || board[ni][nj] == -1) {
                        live_neighbors++;
                    }
                }
            }

            if(board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                board[i][j] = -1;
            }
            if(board[i][j] == 0 && live_neighbors == 3) {
                board[i][j] = 2;
            }
        }
        
       }
       for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};