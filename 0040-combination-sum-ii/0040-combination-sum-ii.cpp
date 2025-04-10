class Solution {
public:
vector<vector<int>>res;

  void solve(int i,vector<int>&nums,vector<int>temp,int target){
   if(target==0){
    res.push_back(temp);
    return;
   }
    int n=nums.size();
    for(int j=i;j<n;j++){
        if(j!=i&&nums[j]==nums[j-1])
        continue;
        if(target>=nums[j]){
     temp.push_back(nums[j]);
     solve(j+1,nums,temp,target-nums[j]);
     temp.pop_back();
        }
    }
  }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
        solve(0,candidates,{},target);
        return res;
    }
};