class Solution {
public:
    //Mamoization
    int dp[46];  // DP array to store results for up to 45 stairs

    int solve(int n) {
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
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
