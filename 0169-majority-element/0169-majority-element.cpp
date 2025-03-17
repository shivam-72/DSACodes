class Solution {
public:
    int majorityElement(vector<int>& nums) {
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
        return res;
    }
};