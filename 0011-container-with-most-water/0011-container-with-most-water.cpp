class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxArea=INT_MIN;
        while(left<right) {
            int current_area = (right-left) * min(height[left], height[right]);
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            maxArea = max(maxArea, current_area);
        }
        return maxArea;
    }
};