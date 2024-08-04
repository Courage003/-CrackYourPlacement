class Solution {
public:
int dp[1001][1001];
    int solve(vector<vector<int>>&nums, int i, int prev){
        int n=nums.size();
        if(i>=n)
            return 0;
        

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        //take the ith number
        int take=0;
        if(prev==-1 || nums[prev][1]<nums[i][0])
            take=1+solve(nums,i+1,i);
        

        //not take
        int skip=solve(nums,i+1,prev);

        return dp[i][prev+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(begin(pairs),end(pairs));
        memset(dp,-1,sizeof(dp));
        return solve(pairs,0,-1);
        
    }
};