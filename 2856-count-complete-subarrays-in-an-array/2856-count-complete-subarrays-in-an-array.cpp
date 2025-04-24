class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k ;
        unordered_map<int,int>cal;

        for(auto &num : nums){
            cal[num]++;
        }
        k = cal.size();

        unordered_map<int,int>mp;
        int cnt =0;
        int n= nums.size();
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>=k && i<=j){
                cnt+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};