class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>m;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                return -1;
            }
            if(m.find(nums[i])==m.end()&&nums[i]!=k){
                m.insert(nums[i]);
                c++;
            }
        }
        return c;
    }
};