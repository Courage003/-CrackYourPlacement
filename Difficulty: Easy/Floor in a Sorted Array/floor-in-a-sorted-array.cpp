//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &nums, long long n, long long x) {

        // Your code here
        long long start=0;
        long long end=n-1;
       
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(nums[mid]>x){
                //delete right portion
                end=mid-1;
            }
            else if(nums[mid]<x){
               
                start=mid+1;
            }
            else if(nums[mid]==x){
                return mid;
            }
            
        }
        return start-1;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends