class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>v(501,0);
        for(auto x:nums){
            v[x]++;
        }
        for(auto x:v){
            if(x%2!=0)
            return false;
        }
        return true;
    }
};