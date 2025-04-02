class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<long long>l(n),r(n);
        l[0]=nums[0];
        for(int i=1;i<n;i++){
          l[i]=max((long long)nums[i],l[i-1]);
        }
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
         r[i]=max((long long)nums[i],r[i+1]);
        }
        for(int i=1;i<n-1;i++){
         ans=max(ans,(l[i-1]-nums[i])*r[i+1]);
        }
        return ans;
    }
};