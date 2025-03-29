class Solution {
public:
    const int MOD = 1e9+7;
    
    // Function to compute (base^exp) % MOD using fast exponentiation
    long long modPower(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) { // If exp is odd, multiply base
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());

        // Sieve to count the number of distinct prime factors for each number
        vector<int> primeFactorCount(maxValue + 1, 0);
        for (int i = 2; i <= maxValue; i++) {
            if (primeFactorCount[i] == 0) { // Prime number found
                primeFactorCount[i]++;
                for (int j = 2; i * j <= maxValue; j++) {
                    primeFactorCount[i * j]++;
                }
            }
        }
        
        // Compute next greater element index to the right (next larger prime factor count)
        vector<int> nextGreater(n, n);
        stack<int> monoStack;
        monoStack.push(n);
        for (int i = n - 1; i >= 0; i--) {
            while (monoStack.top() < n && primeFactorCount[nums[monoStack.top()]] <= primeFactorCount[nums[i]]) {
                monoStack.pop();
            }
            nextGreater[i] = monoStack.top();
            monoStack.push(i);
        }
        
        // Clear stack to reuse for previous greater element computation
        while (!monoStack.empty()) {
            monoStack.pop();
        }
        
        // Compute previous greater element index to the left (previous larger prime factor count)
        vector<int> prevGreater(n, -1);
        monoStack.push(-1);
        for (int i = 0; i < n; i++) {
            while (monoStack.top() > -1 && primeFactorCount[nums[monoStack.top()]] < primeFactorCount[nums[i]]) {
                monoStack.pop();
            }
            prevGreater[i] = monoStack.top();
            monoStack.push(i);
        }
        
        // Sorting indices based on values in descending order
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](const int idx1, const int idx2) {
            return nums[idx1] > nums[idx2];
        });
        
        long long maxScore = 1;
        for (int& index : indices) {
            long long element = nums[index];
            long long rightRange = nextGreater[index] - index; // Range of influence to the right
            long long leftRange = index - prevGreater[index]; // Range of influence to the left
            long long contribution = leftRange * rightRange; // Total contribution
            long long exponent = min(contribution, (long long)k);
            
            maxScore = (maxScore * modPower(element, exponent)) % MOD;
            k -= exponent;
            
            if (k <= 0) break;
        }
        return maxScore;
    }
};