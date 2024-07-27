class Solution {
public:
    
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size()!=target.size()) return -1;
        
        vector<vector<long long>>vis(26,vector<long long>(26,1e12));
        vis[0][0]=0;
        for(int i=0;i<26;i++) vis[i][i]=0;
        int n=original.size();
        for(int i=0;i<n;i++){
            vis[original[i]-'a'][changed[i]-'a']=min(vis[original[i]-'a'][changed[i]-'a'],static_cast<long long>(cost[i]));
        }
        
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                for(int l=0;l<26;l++){
                    if(vis[k][j]==1e12 || vis[j][l]==1e12) continue;
                    
                    vis[k][l]=min(vis[k][l],vis[k][j]+vis[j][l]);
                }
            }
        }
        long long res=0;
        int m=source.size();
        
        for(int i=0;i<m;i++){
            long long rem=vis[source[i]-'a'][target[i]-'a'];
            
            if(rem==1e12){
                return -1;
            }
            res+=rem;
        }
        return res;
    }
};