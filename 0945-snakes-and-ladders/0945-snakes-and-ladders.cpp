class Solution {
public:
    pair<int, int> getRowCol(int s, int n) {
        int row = n-1-(s-1)/n;
        int rowFromBottom = (s-1)/n;
        int col;
        if(rowFromBottom % 2 == 0) {
            col = (s-1)%n;
        } else {
            col = n-1-(s-1)%n;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n*n+1, false);
        queue<pair<int, int>> q;

        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if(curr == n * n) return moves;

            for(int next = curr+1; next<=min(curr+6, n*n); next++) {
                auto[r, c] = getRowCol(next, n);
                int dest = (board[r][c] == -1 ? next : board[r][c]);

                if(!visited[dest]) {
                    visited[dest] = true;
                    q.push({dest, moves+1});
                }
            }
        }
        return -1;
    }
};