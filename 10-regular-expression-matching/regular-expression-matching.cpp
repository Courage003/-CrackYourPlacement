class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j,string s, string p){
        int m=s.size();
        int n=p.size();
        if(j==n){
            return i==m;
        } //base case
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //case of <ch>* and .*
        bool firstcharmatch=false;

        if(i<m && (p[j]==s[i] || p[j]=='.')){
            firstcharmatch=true;
        }
        if(p[j+1]=='*'){
            bool nottake=solve(i,j+2,s,p); //case of ignore
            bool take=firstcharmatch && solve(i+1,j,s,p);
            return dp[i][j]=nottake || take;
        }
        
        return dp[i][j]=firstcharmatch && solve(i+1,j+1,s,p);
        
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
        
    }
};