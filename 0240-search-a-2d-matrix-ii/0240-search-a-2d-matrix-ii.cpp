class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int key) {
        int row = 0, col = mat[0].size()-1;
        int n = mat.size();

        while(row < n && col >= 0) {
            if(mat[row][col] == key) return true;
            else if(mat[row][col] < key) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};