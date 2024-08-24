class Solution {
public:
int dp[2002][2002];
bool solve(int i, int j, string &s, string &p){
    int m=s.size();
    int n=p.size();

    if(j==n){
        return i==m;
    } //base case

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    bool firstcharmatch=false;

    if(i<m && (p[j]==s[i] || p[j]=='?')){
        firstcharmatch=true;  //matches any single character
    }

    if(j< n && p[j]=='*'){
        bool nottake=solve(i,j+1,s,p);
        bool take=(i<m) && solve(i+1,j,s,p); //matches one or more characters

        return dp[i][j]=nottake || take;
    }

    return dp[i][j]=firstcharmatch && solve(i+1,j+1,s,p);  
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
        
        
    }
};