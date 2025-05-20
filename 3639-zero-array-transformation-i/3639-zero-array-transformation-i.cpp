class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
     {
        int cnt = 0;
        vector<int>dp(nums.size(),0);
        unordered_map<int,int>st;
        unordered_map<int,int>end;
        for(auto v:queries)
        {
            st[v[0]]++;
            end[v[1]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(i)!=st.end())
            {
                cnt += st[i];
            }
            if(nums[i]>cnt)
            {
                return false;
            }
             if(end.find(i)!=end.end())
            {
                cnt -= end[i];
            } 
        }
        
        return true;
        
    }
};