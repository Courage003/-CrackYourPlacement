//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, string& w1, string& w2) {
        if (i >= m) {
            return n - j;  // Remaining characters in w2 to be inserted
        }
        if (j >= n) {
            return m - i;  // Remaining characters in w1 to be deleted
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (w1[i] == w2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, w1, w2);
        }

        int insert = 1 + solve(i, j + 1, w1, w2);
        int deletion = 1 + solve(i + 1, j, w1, w2);
        

        return dp[i][j] = min(insert, deletion);
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    m = str1.size();
        n = str2.size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return solve(0, 0, str1, str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends