class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=0;
        while(i<=j){
            if(nums[i]==0){
                swap(nums[k],nums[i]);
                k++;
                i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[j],nums[i]);
                j--;
            }
        }
    }
};