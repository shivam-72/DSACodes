class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0,s=nums.size(),res=0;
        for(;i<s-2;i++)
        {
            if(nums[i]==1)
            continue;
            res++;
            nums[i]=1;
            if(nums[i+1]==0)
            nums[i+1]=1;
            else
            nums[i+1]=0;
            if(nums[i+2]==0)
            nums[i+2]=1;
            else
            nums[i+2]=0;
        }
        for(i=0;i<s;i++)
        if(nums[i]==0)
        return -1;
        return res;
    }
};