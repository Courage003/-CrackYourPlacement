class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto &it: times){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }
         set<pair<int,int>>st;
        vector<int>res(n+1, INT_MAX);
        res[k]=0;
        
        //pq.push({0,Source});
        st.insert({0,k});
        
        while(!st.empty()){
            auto &it = *st.begin();
            /*int d=pq.top().first;
            int node=pq.top().second;*/
            int d= it.first;
            int node= it.second;
            
            //pq.pop();
            st.erase(it);
            
            for(auto &i: adj[node]){
                int adjNode=i.first;
                int wt=i.second;
                
                if(d+wt<res[adjNode]){
                    
                    if(res[adjNode]!=INT_MAX){
                        st.erase({res[adjNode], adjNode});
                    }
                    res[adjNode]=d+wt;
                    st.insert({d+wt,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,res[i]);
        }

        return ans==INT_MAX? -1: ans;

        
    }
};