class Solution {
public:
     int dp[501][501];
    int solve(string &s1,string &s2,int m,int n){
       
        if(m==s1.size())
            return dp[m][n]= s2.size()-n;
        if(n==s2.size())
            return dp[m][n]= s1.size()-m;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s1[m]==s2[n]){
            return dp[m][n]=solve(s1,s2,m+1,n+1);
        }
        else
        {
            return dp[m][n]= 1+min(solve(s1,s2,m,n+1),min(solve(s1,s2,m+1,n),solve(s1,s2,m+1,n+1)));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
       return solve(word1,word2,0,0);
    }
};