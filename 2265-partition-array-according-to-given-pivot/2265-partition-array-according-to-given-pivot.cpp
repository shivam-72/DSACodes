class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>v(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                v[j]=nums[i];
                j++;
            }
        }
        for(auto x:nums){
            if(x==pivot){
                v[j]=x;
                j++;
            }
        }
        for(auto x:nums){
            if(x>pivot){
                v[j]=x;
                    j++;
                }
        }
        return v;
    }
};