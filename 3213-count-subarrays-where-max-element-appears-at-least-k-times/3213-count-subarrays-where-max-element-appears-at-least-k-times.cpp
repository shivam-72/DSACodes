class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int i=0;
        int j=0;
        long long n=nums.size();
        int a=*max_element(nums.begin(),nums.end());
        int c=0;
        while(j<n){
          if(nums[j]==a)
            c++;
            while(i<n&&c>=k){
                if(nums[i]==a)
                c--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        long long p =n*(n+1)/2;
        return p-ans;
    }
};