//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static lambda(pair<int,int>&a, pair<int,int>&b){
        return a.second<b.second || (a.second==b.second && a.first<=b.first);
    }
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        
        vector<pair<int,int>>meet;
        for(int i=0;i<n;i++){
            meet.push_back({start[i],end[i]});
        }
        
        sort(meet.begin(),meet.end(),lambda);
        
        int res=1;
        int endTime=meet[0].second;
        for(int i=1;i<n;i++){
            if(endTime<meet[i].first){
                res++;
                endTime=meet[i].second;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends