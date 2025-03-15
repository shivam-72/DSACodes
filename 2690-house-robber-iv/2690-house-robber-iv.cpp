class Solution {
public:
    int func(vector<int> &a, int k, int i, vector<int> &dp1){
        if(i>=a.size()){
            return 0;
        }
    if(dp1[i]!=-1){
        return dp1[i];
    }
        int take=0;
        int nt=func(a,k,i+1,dp1);
        
        if(a[i]<=k){
            return dp1[i]= max(func(a,k,i+2,dp1)+1,nt);
        }
        return dp1[i]= nt;
    }
    
    bool chk(vector<int> &a, int k, int req){
        vector<int> dp1(a.size());
        for(int i=0;i<a.size();i++){
            dp1[i]=-1;
        }
        int maxi=func(a,k,0,dp1);
        return maxi>=req;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int st=0;
        int ed=1000000000;
        while(st+1<ed){
            int m=st+(ed-st)/2;
            if(chk(nums,m,k)){
                ed=m;
            }
            else{
                st=m;
            }
            
        }
        
        return ed;
    }
};