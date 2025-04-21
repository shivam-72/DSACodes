class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, minSum = 0, maxSum = 0;
        for (int d : differences) {
            sum += d;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }
        long long range = (long long)upper - lower;
        long long width = maxSum - minSum;
        return range < width ? 0 : range - width + 1;
    }
};