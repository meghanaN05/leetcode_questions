class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mid = m - 1;
        int nid = n - 1;
        int r = m + n - 1;

        while (nid>= 0) {
            if (mid >= 0 && nums1[mid] > nums2[nid]) {
                nums1[r] = nums1[mid];
                mid--;
            } else {
                nums1[r] = nums2[nid];
                nid--;
            }
            r--;
        }        
    }
};