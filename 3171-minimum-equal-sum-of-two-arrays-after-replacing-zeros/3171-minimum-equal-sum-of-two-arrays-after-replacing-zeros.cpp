class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long z1 = 0, z2 = 0, s1 =0, s2 = 0;

        for(auto n: nums1){
            z1 += (n == 0)? 1: 0;
            s1 += n;
        }
        for(auto n: nums2){
            z2 += (n == 0)? 1: 0;
            s2 += n;
        }
        if(z1 ==0 && z2 ==0 && s1 != s2)
            return -1;
        
        if(z1 == 0 && s1 < s2+z2 || (z2 ==0 && s1+z1 > s2))
            return -1;
        
        return max(s1+z1, s2+z2);
    }
};