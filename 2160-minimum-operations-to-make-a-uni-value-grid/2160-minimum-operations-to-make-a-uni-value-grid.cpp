class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto &row : grid) {
            for (int it : row) {
                nums.push_back(it);
            }
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];

        for (int it : nums) {
            if ((it - median) % x != 0) return -1;
        }

        int cnt = 0;
        for (int it : nums) {
            cnt += abs(it - median) / x;
        }

        return cnt;
    }
};