class Solution {
public:
    //Mamoization
    int dp[46];  // DP array to store results for up to 45 stairs

    int solve(int n) {
        //Top down approach started from 3 then -1 and -2
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int one_step = solve(n - 1);
        int two_step = solve(n - 2);
        return dp[n] = one_step + two_step;
    }

    int climbStairs(int n) {
        /*memset(dp, -1, sizeof(dp));
        return solve(n);*/

        //Tabulation approach (bottom up)
        if(n==1 || n==2 || n==3)
            return n;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
