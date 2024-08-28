class Solution {
public:
    int n;
    int dp[2001][2001];
    unordered_map<int,int>mp;
    bool solve(vector<int>&stones, int curr_stone_idx, int prevjump){
        n=stones.size();
        if(curr_stone_idx==n-1){
            return true;
        }
        if(dp[curr_stone_idx][prevjump]!=-1){
            return dp[curr_stone_idx][prevjump];
        }
        bool res=false;
        for(int nextjump=prevjump-1;nextjump<=prevjump+1;nextjump++){
            if(nextjump>0){
                int next_stone=stones[curr_stone_idx]+nextjump;
                if(mp.find(next_stone)!=mp.end()){
                    res=res || solve(stones,mp[next_stone],nextjump);
                }
            }
        }
        return dp[curr_stone_idx][prevjump]=res;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(dp,-1,sizeof(dp));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        return solve(stones,mp[0],0);
    }
};