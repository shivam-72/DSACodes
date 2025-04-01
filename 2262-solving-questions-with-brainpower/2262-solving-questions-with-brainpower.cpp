class Solution {
public:
long long dp[100005];
long long solve(vector<vector<int>>&v,int i){
    if(i>=v.size())
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    return dp[i]=max(solve(v,i+1),v[i][0]+solve(v,v[i][1]+1+i));
}
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }
};