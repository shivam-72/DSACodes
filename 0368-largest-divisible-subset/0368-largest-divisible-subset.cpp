class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n,1);
       int mx=0;
       sort(nums.begin(),nums.end());
       vector<int>par(n);
       int lastid=0;
       par[0]=0;
       for(int i=1;i<nums.size();i++){
           for(int j=0;j<i;j++){
             if(nums[i]%nums[j]==0){
                 if(dp[i]<dp[j]+1){
                 dp[i]=dp[j]+1;
                  par[i]=j;
                 }
             }
           }
            if(dp[i]==1)
            par[i]=i;
            if(mx<dp[i]){
           mx=max(mx,dp[i]);
           lastid=i;
            }
       } 
       int c=lastid;
       vector<int>ans;
       while(c!=par[c]){
       ans.push_back(nums[c]);
       c=par[c];
        }
        ans.push_back(nums[c]);
       return ans;
    }
};