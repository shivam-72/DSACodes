class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](vector<int>&A, vector<int>&B) {
            return A[0]<B[0];
        });

        int n = nums.size();
        int m = queries.size();

        vector<int>outOfRange(n+1, 0);

        priority_queue<int>PQ;

        int count = 0;
        int j=0;
        for(int i=0;i<n;i++) {
            count += outOfRange[i];
            while(j<m && queries[j][0]==i) {
                PQ.push(queries[j][1]);
                j++;
            }
            while(count<nums[i] && !PQ.empty() && PQ.top()>=i) {
                count++;
                auto x = PQ.top();
                PQ.pop();
                outOfRange[x+1]--;
            }
            if(count<nums[i])
                return -1;
        }
        return PQ.size();
    }
};