//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
}
    string infixToPostfix(string s) {
        // Your code here
        int i=0;
        int n=s.size();
        stack<char>st;
        string res="";
        
        while(i<n){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                res+=s[i];
            }
            
            else if(s[i]=='('){
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                //operators
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends