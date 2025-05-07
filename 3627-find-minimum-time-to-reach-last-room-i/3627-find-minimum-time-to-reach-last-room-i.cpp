class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});
        minTime[0][0] = 0;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!minHeap.empty()) {
            vector<int> current = minHeap.top();
            minHeap.pop();
            int currentTime = current[0];
            int currentRow = current[1];
            int currentCol = current[2];
            if (currentTime > minTime[currentRow][currentCol]) continue;

            for (const vector<int>& direction : directions) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newTime = max(currentTime, moveTime[newRow][newCol]) + 1;
                    if (newTime < minTime[newRow][newCol]) {
                        minTime[newRow][newCol] = newTime;
                        minHeap.push({newTime, newRow, newCol});
                    }
                }
            }
        }
        return minTime[rows-1][cols-1];
    }
};