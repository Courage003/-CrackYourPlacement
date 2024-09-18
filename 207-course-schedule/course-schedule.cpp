class Solution {
    
public:
    bool isCycle=false;

    void dfs(unordered_map<int,vector<int>>&adj, int u, stack<int>&st, vector<bool>&vis, vector<bool>&inRecursion){
        vis[u]=true;
        inRecursion[u]=true;
        //marked true because
        for(auto it:adj[u]){
            if(!vis[it] && inRecursion[it]==false){
                dfs(adj,it,st,vis,inRecursion);

            }
            else if(inRecursion[it]==true){
                isCycle=true;
                return;
            }
        }
        st.push(u);
        inRecursion[u]=false;

    }
    vector<int>topoSort(vector<vector<int>>& prerequisites, int n){
        unordered_map<int,vector<int>>adj;
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        //adjacency list
        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);
        //taken for keeping track of cycle from the source
        stack<int>st;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,st,vis,inRecursion);
            }
        }

        if(isCycle) return {};
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;

        

    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>topoRow=topoSort(prerequisites,n);
        return !topoRow.empty();
    }
};