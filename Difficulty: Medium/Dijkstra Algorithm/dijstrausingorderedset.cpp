//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int Source)
    {
        // Code here
        
        //distance,vertex
        set<pair<int,int>>st;
        vector<int>res(V, INT_MAX);
        res[Source]=0;
        
        //pq.push({0,Source});
        st.insert({0,Source});
        
        while(!st.empty()){
            auto &it = *st.begin();
            /*int d=pq.top().first;
            int node=pq.top().second;*/
            int d= it.first;
            int node= it.second;
            
            //pq.pop();
            st.erase(it);
            
            for(auto &i: adj[node]){
                int adjNode=i[0];
                int wt=i[1];
                
                if(d+wt<res[adjNode]){
                    
                    if(res[adjNode]!=INT_MAX){
                        st.erase({res[adjNode], adjNode});
                    }
                    res[adjNode]=d+wt;
                    st.insert({d+wt,adjNode});
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
