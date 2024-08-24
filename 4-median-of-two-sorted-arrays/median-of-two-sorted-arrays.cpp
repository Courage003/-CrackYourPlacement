class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        /*//vector<int> temp(m + n);
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
            }

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
        return (elem1+elem2)/2.0;*/

        //Binary Search approach


        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }

        int l=0;
        int r=m;

        while(l<=r){
            int Px=l+(r-l)/2;
            int Py=(m+n+1)/2-Px;
            //left half
            int x1=(Px==0)? INT_MIN: nums1[Px-1];
            int x2=(Py==0)? INT_MIN: nums2[Py-1];
            //right half
            int x3=(Px==m)? INT_MAX: nums1[Px];
            int x4=(Py==n)? INT_MAX: nums2[Py];

            if(x1<=x4 && x2<=x3){
                if((m+n)%2==0){
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
                else{
                return max(x1,x2);
                }
            }

            if(x1>x4){
                r=Px-1;
            }
            else{
                l=Px+1;
            }
        }
        return -1;
    }
};
