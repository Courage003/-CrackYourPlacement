class Solution {
public:
//mamoization to decrease cases of repeating sequences
    int dp[2501][2501];
    int solve(vector<int>&nums, int i, int prev){
        int n=nums.size();
        if(i>=n){
            return 0;
        }

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        //take the ith number
        int take=0;
        if(prev==-1 || nums[prev]<nums[i])
            take=1+solve(nums,i+1,i);
        

        //not take
        int skip=solve(nums,i+1,prev);

        return dp[i][prev+1]=max(take,skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        /*int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);*/

        int n=nums.size();
        //Bottom Up Approach

        vector<int>dp(n,1);
        //state definition
        int maxLIS=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                dp[i]=max(dp[i],dp[j]+1);
                maxLIS=max(maxLIS,dp[i]);
            }
        }
        return maxLIS;
        
    }
};