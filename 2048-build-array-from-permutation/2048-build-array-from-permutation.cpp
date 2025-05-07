class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        m[i]=nums[i];
        vector<int> v(nums.size());
        for(int i=0;i<nums.size();i++)
        v[i]=m[nums[i]];
        return v;
    }
};