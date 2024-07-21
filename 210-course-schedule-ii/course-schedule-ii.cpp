class Solution {
public:

    void dfs(int u, unordered_map<int,vector<int>>&adj, vector<int>&vis, stack<int>&st, bool &cycle){
        vis[u]=1;

        for(auto &i: adj[u]){
            if(vis[i]==0){
                dfs(i,adj,vis,st,cycle);
            }
            else if(vis[i]==1){
                cycle=true;
                return;
            }
        }
        vis[u]=2;
        st.push(u);
    }

    vector<int>topoSort(vector<vector<int>>&edges, int n){
        unordered_map<int,vector<int>>adj;
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        vector<int>vis(n+1,0);
        stack<int>st;
        vector<int>res;
        bool cycle=false;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,st,cycle);
            }
            if(cycle){
                return {};
            }
        }


        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>topoRow = topoSort(prerequisites,n);
        if(topoRow.empty()){
            return {};
        }
        reverse(begin(topoRow),end(topoRow));
        return topoRow;
        
    }
};