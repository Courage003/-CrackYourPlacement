class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        //vector<int> temp(m + n);
        int i = 0;
        int j = 0;
        int k = 0; // Index for temp
        int size=(m+n);
        int idx1=(size/2)-1;
        int elem1=-1;
        int idx2=(size/2);
        int elem2=-1;

        // Merge the two arrays
        while (i < m && j < n) {
            /*if (nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }*/

            if(nums1[i]<nums2[j]){
                if(k==idx1){
                    elem1=nums1[i];
                }
                if(k==idx2){
                    elem2=nums1[i];
                }
                i++;
            }
            else{
                if(k==idx1){
                    elem1=nums2[j];
                }
                if(k==idx2){
                    elem2=nums2[j];
                }
                j++;
            }
            k++;
        }

        // If there are remaining elements in nums1
        while (i < m) {
            //temp[k++] = nums1[i++];
            if(k==idx1){
                    elem1=nums1[i];
                }
            if(k==idx2){
                    elem2=nums1[i];
                }
                i++;
                k++;
        }

        // If there are remaining elements in nums2
        while (j < n) {
            //temp[k++] = nums2[j++];
            if(k==idx1){
                    elem1=nums2[j];
                }
            if(k==idx2){
                    elem2=nums2[j];
                }
                j++;
                k++;
        }

        //int size = temp.size();

        // If the merged array size is odd, return the middle element
        if (size % 2 == 1) {
            //return temp[size / 2];
            return elem2;
        }

        // If the merged array size is even, return the average of the two middle elements
        //return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;
        return (elem1+elem2)/2.0;
    }
};
