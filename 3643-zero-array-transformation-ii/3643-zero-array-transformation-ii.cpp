class Solution {
public:
    int solve(vector<vector<int>>& queries,vector<int>nums,int k){
        int n=queries.size();
        int n2=nums.size();
        vector<int>v2(n2);
        for(int i=0;i<k;i++){
          int l=queries[i][0];
          int r=queries[i][1];
          int mx=queries[i][2];
           v2[l]+=mx;
           if(r+1<n2)
           v2[r+1]-=mx;
        }
        for(int i=1;i<n2;i++){
            v2[i]=v2[i]+v2[i-1];
        }
        for(int i=0;i<n2;i++){
         if(nums[i]>v2[i])
         return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int i=0;
        int n=queries.size();
        int j=n;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(solve(queries,nums,mid)){
                ans=mid;
                j=mid-1;
            }
            else
              i=mid+1;
        }
        return ans;
    }
};