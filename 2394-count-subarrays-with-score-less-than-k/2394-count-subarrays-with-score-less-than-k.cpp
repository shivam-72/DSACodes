class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0;
        int j=0;
       unsigned long long p=0;
        int d=0;
        long long c=0;
        int n=nums.size();
        while(j<nums.size()){
            p+=nums[j];
            d++;
            while(i<n&&d*p>=k){
                p-=nums[i];
                i++;
                d--;
            }
          c+=j-i+1;
            j++;
        }
        return c;
    }
};