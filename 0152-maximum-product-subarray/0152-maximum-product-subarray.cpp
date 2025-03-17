class Solution {
public:
    int maxProduct(vector<int>& nums) {
      long long maxi = INT_MIN;
        long long prod=1;
        for(int i=0;i<nums.size();i++)
        {
            if(prod==0)
            prod=nums[i];
            else
          prod*=nums[i];
        
            maxi=max(prod,maxi);
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
         if(prod==0)
            prod=nums[i];
            else
          prod*=nums[i];
            maxi=max(prod,maxi);
        }
        return maxi;
    }
};