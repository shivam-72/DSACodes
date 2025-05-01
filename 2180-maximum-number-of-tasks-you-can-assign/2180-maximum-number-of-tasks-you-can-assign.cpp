class Solution {
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int workersSize = workers.size();
        multiset<int> workersSet(workers.begin() + workersSize - mid, workers.end());
        for(int i = mid - 1; i >= 0; i--) {
            if(*workersSet.rbegin() >= tasks[i]) {
                workersSet.erase(--workersSet.end());
            } else {
                if(pills == 0) return false;
                auto it = workersSet.lower_bound(tasks[i] - strength);
                if(it == workersSet.end())
                    return false;
                pills--;
                workersSet.erase(it);
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 1, high = min(tasks.size(), workers.size()), ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(tasks, workers, pills, strength, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};