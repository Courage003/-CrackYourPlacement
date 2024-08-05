//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001]; // Reduce the size to fit within typical constraints

    int solve(vector<int>& arr, int id, int prev) {
        int n = arr.size();
        if (id >= n) {
            return 0;
        }
        if (dp[id][prev + 1] != -1) {
            return dp[id][prev + 1];
        }
        int take = 0;
        int skip = 0;
        if (prev == -1 || arr[prev] < arr[id]) {
            take = arr[id] + solve(arr, id + 1, id);
        }
        skip = solve(arr, id + 1, prev);
        return dp[id][prev + 1] = max(take, skip);
    }
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    vector<int>v(arr,arr+n);
	    return solve(v,0,-1);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends