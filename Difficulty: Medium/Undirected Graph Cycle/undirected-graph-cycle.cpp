//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCycleDFS(int u, vector<int>adj[], vector<bool>&vis, int parent){
        vis[u]=true;
        for(int &v: adj[u]){
            if(v==parent) continue;
            
            if(vis[v]) return true;
            
            if(isCycleDFS(v,adj,vis,u)) return true;
        }
        return false;
    }
    
    bool isCycleBFS(int u, vector<int>adj[], vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({u,-1});
        vis[u]=true;
        
        
        while(!q.empty()){
            pair<int,int>P=q.front();
            q.pop();
            int src=P.first;
            int parent=P.second;
            
            for(int &v: adj[src]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push({v,src});
                }
                else if(v!=parent){
                    return true;
                }
            }
            
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleBFS(i,adj,vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends