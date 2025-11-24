/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isUniform(vector<vector<int>>& grid, int r, int c, int len) {
        int first = grid[r][c];
        for(int i=r; i < r + len; i++) {
            for(int j = c; j < c + len; j++) {
                if(grid[i][j] != first) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* build(vector<vector<int>>& grid, int r, int c, int len) {
        if(isUniform(grid, r, c, len)) {
            return new Node(grid[r][c] == 1, true);
        }

        int half = len / 2;

        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c+half, half);
        Node* bottomLeft = build(grid, r+half, c, half);
        Node* bottomRight = build(grid, r+half, c+half, half);

        return new Node (
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
};