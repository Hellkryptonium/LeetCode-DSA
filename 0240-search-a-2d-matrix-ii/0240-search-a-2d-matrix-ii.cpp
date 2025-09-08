class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int key) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++) {
            int st=0, end = m-1;
            while(st <= end) {
                int mid = st + (end-st)/2;
                if(mat[i][mid] == key) return true;
                else if(mat[i][mid] <= key) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};