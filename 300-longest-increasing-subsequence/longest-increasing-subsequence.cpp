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
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
        
    }
};