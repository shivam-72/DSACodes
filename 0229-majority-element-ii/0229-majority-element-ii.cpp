class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=1e9+1;
        int j=1e9+1;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==a){
            count1++;
          }
          else if(nums[i]==j){
            count2++;
          }
          else if (count1==0){
            a=nums[i];
            count1=1;
          }
          else if(count2==0){
            j=nums[i];
            count2=1;
          }
        
          else{
            count1--;
            count2--;
          }
        }
        count1=0;
        count2=0;
        for(auto x:nums){
            if(x==a){
             count1++;
            }
            else if(x==j){
             count2++;
            }
        }
        int n=nums.size();
        vector<int>ans;
        if(count1>(n/3))
        ans.push_back(a);
        if(count2>(n/3))
        ans.push_back(j);
        return ans;
    }
};