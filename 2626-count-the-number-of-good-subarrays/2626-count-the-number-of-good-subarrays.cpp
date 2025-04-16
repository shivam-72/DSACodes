class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
     long long n = nums.size();
        long long curr = 0;
        long long res = 0;
        unordered_map<long long, long long> m;
        int i=0;
        int j=0;
        long long pairs=0;
        while(j<n){
            m[nums[j]]++;
            pairs+=(m[nums[j]]-1);
            while(i<n&&pairs>=k){
                res+=n-j;
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                pairs-=m[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};