class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> temp(n+m);
        
        int i=0, j=0, k=0;
        
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }
        
        while(i < n) {
            temp[k++] = nums1[i++];
        }
        
        while(j < m) {
            temp[k++] = nums2[j++];
        }
        
        int size = temp.size();
        
        if(size % 2 == 0) {
            int a = temp[size/2];
            int b = temp[(size/2)-1];
            return (double)((a+b)/2.0);
            
        } else {
            return (double)temp[size/2];
        }
        return 0.0;
    }
};