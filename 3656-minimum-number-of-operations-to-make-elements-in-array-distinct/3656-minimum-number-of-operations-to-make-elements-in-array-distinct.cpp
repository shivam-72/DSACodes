class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int st=-1;
        for(int i=n-1;i>=0;i--){
            if(m.find(nums[i])!=m.end()){
                st=i;
                break;
            }
            m[nums[i]]=1;
        }
        if(st==-1)
            return 0;
        int num=st+1;
        int ans=num/3;
        if(num%3==0)
            return ans;
        return ans+1;
    }
};