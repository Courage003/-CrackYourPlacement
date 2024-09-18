class Solution {
   
public:
    int n;
    void dfs(vector<vector<int>>&isConnected, int u, vector<bool>&vis){
        vis[u]=true;
       
        for(int v=0;v<n;v++){
            if(!vis[v] && isConnected[u][v]==1){
                dfs(isConnected,v,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       n=isConnected.size();
       vector<bool>vis(n,false);
       int cnt=0;
       for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected, i,vis);
                cnt++;
            }
       }
       return cnt;
        
    }
};