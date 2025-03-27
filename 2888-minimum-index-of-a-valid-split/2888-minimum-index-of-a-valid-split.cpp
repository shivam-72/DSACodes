class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int count=0;
        int res=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==res){
               count++;
            }
           else if(count==0){
               res=nums[i];
                count=1;
            }
           
            else
                count--;
        }
        count=0;
        for(auto x:nums){
            if(x==res)
            count++;
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==res){
            c++;
           }
           if(c*2>(i+1)&&(count-c)*2>(nums.size()-(i+1))){
            return i;
           }
        }
        return -1;
    }
};