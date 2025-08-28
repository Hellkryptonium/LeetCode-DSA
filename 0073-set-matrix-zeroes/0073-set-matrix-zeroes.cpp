class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        //step 1 flags for first & first column
        bool rowZero = false, colZero = false;

        //check if first row has any zero
        for(int j=0; j<n; j++) {
            if(matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }

        //check if first column has any zero
        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }

        //step 2 use first row & column as markers
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //step 3 set cells to zero based on markers
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        //step 4: handle first row zero
        if(rowZero) {
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }

        //step 5 handle first column
        if(colZero) {
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};