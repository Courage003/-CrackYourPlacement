//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
         stack<string> st;
        int n = s.size();

        // Traverse the postfix expression from left to right
        for (int i = 0; i < n; i++) {
            // If the character is an operand, push it to the stack
            if (isalnum(s[i])) {
                st.push(string(1, s[i])); // Convert char to string and push
            }
            // If the character is an operator, pop two elements, form the prefix expression, and push it back
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                // Form the prefix expression (operator + operand1 + operand2)
                string prefix = s[i] + t2 + t1;
                st.push(prefix);
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends