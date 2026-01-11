class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
        height.push_back(0);
        int maxArea = 0;

        for(int i=0; i<height.size(); i++) {
            while(!st.empty() && height[st.top()] > height[i]) {
                int h = height[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        height.pop_back();
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);

        int ans = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j]+1 : 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};