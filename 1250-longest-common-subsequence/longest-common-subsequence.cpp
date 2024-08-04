class Solution {
public:
    int dp[1001][1001];

    int solve(string s1, string s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        /*memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);*/
         int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
