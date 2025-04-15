//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>&counter){
        for(auto &i: counter){
            if(i!=0){
                return false;
            }
            
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n=txt.size();
        
        //keeping frequency of words present in pat word
        vector<int>counter(26,0);
        for(int i=0;i<pat.size();i++){
            char ch=pat[i];
            counter[ch-'a']++;
        }
        
        //SLiding window approach
        int i=0,j=0;
        
        int res=0;
        while(j<n){
            counter[txt[j]-'a']--;
            
            if(j-i+1==pat.size()){
                if(allZero(counter)){
                    res++;
                }
                
                counter[txt[i]-'a']++;
                i++;
            }
            j++;
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends