//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Sort the arrival and departure times
        sort(arr, arr + n);
        sort(dep, dep + n);

        // Initialize pointers for arrivals and departures
        int i = 1, j = 0;

        // Initialize platform count and result
        int plat = 1;
        int maxi = 1;

        // Traverse through all arrival and departure events
        while (i < n && j < n) {
            // If the next event is an arrival
            if (arr[i] <= dep[j]) {
                plat += 1; // Increase platform count
                i++;
            } else if(arr[i]>dep[j]) {
                // If the next event is a departure
                plat -= 1; // Decrease platform count
                j += 1;
            }
            // Update the maximum platforms needed
            if(plat>maxi)
            maxi=plat;
        }
        return maxi; // Return the maximum number of platforms needed
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends