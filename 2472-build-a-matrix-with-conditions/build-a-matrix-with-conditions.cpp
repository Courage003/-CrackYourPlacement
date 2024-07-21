class Solution {
public:

    void dfs(int u, vector<int>&vis, unordered_map<int,vector<int>>&adj, stack<int>&st, bool &cycle){
        vis[u]=1;

        for(int &it: adj[u]){
            if(vis[it]==0){
                dfs(it,vis,adj,st,cycle);
            }
            else if(vis[it]==1){
                cycle=true;
                return;
            }
            
           
        }
        vis[u]=2;
        st.push(u);
    }
    vector<int>topoSort(vector<vector<int>>&edges, int &n){
        //adjacency matrix
        unordered_map<int,vector<int>>adj;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }

        vector<int>vis(n+1,0);
        stack<int>st;
        vector<int>res;
        bool cycle=false;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,st,cycle);

                if(cycle){
                    return {};
                }
            }
           
        }
        //vis[i]=0 not visited vis[i]=1 visited ongoing DFS vis[i]=2 visited

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>topoRow = topoSort(rowConditions,k);
        vector<int>topoCol = topoSort(colConditions,k);
        if(topoRow.empty() || topoCol.empty()){
            return {};
        }
        vector<vector<int>>matrix(k,vector<int>(k,0));

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(topoRow[i]==topoCol[j]){
                    matrix[i][j]=topoRow[i];
                }
            }
        }
        return matrix;
    }
};