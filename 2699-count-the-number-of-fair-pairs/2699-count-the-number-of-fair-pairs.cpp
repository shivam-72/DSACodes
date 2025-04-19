class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<n){
            long long c=nums[i];
            long long l=lower-c;
            long long r=upper-c;
            int x1=lower_bound(nums.begin()+i+1,nums.end(),l)-nums.begin();
            int x2=upper_bound(nums.begin()+i+1,nums.end(),r)-nums.begin();
           ans+=(x2-x1);
           i++;
           
        }
        return ans;
    }
};