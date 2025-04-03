class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
         vector<vector<int>>ans;
        if(nums.size()==0 || nums.size()<=3)
            return ans;
       sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
            if(j!=i+1&&nums[j]==nums[j-1]){
                continue;
            }
            long long t=nums[i]+nums[j];
            int l=j+1;
            int r=n-1;
            while(l<r){
                long long g=t;
                g+=nums[r];
                g+=nums[l];
                if(g==target){
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    l++;
                    r--;
                    ans.push_back(v);
                    while(l<r&&nums[l]==nums[l-1]){
                       l++;
                    }
                    while(l<r&&nums[r]==nums[r+1]){
                       r--;
                    }
                }
                else if(g>target){
                    r--;
                }
                else
                    l++;
            }
            }
        }
        return ans;
    }
};