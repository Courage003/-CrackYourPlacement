//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        
         stack<string> st;
        int n = s.size();

        // Traverse the prefix expression from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If the character is an operand, push it to the stack
            if (isalnum(s[i])) {
                st.push(string(1, s[i])); // Convert char to string
            }
            // If the character is an operator, pop two elements, form the expression, and push it back
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                // Form the infix expression with parentheses
                string con = "(" + t1 + s[i] + t2 + ")";
                st.push(con);
            }
        }
        // The final result is the only string left in the stack
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends