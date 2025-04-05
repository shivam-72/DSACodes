class Solution {
public:
     int fun(vector<int>& nums, int index, int currXOR) {
        if (index == nums.size()) return currXOR;
        return fun(nums, index + 1, currXOR ^ nums[index]) + fun(nums, index + 1, currXOR);
    }

    int subsetXORSum(vector<int>& nums) {
        return fun(nums, 0, 0);
    }
}; 