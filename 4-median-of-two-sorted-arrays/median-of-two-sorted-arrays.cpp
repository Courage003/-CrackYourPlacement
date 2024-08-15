class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> temp(m + n);
        int i = 0;
        int j = 0;
        int k = 0; // Index for temp

        // Merge the two arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }

        // If there are remaining elements in nums1
        while (i < m) {
            temp[k++] = nums1[i++];
        }

        // If there are remaining elements in nums2
        while (j < n) {
            temp[k++] = nums2[j++];
        }

        int size = temp.size();

        // If the merged array size is odd, return the middle element
        if (size % 2 == 1) {
            return temp[size / 2];
        }

        // If the merged array size is even, return the average of the two middle elements
        return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;
    }
};
