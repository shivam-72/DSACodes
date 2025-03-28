#define pii pair<int,pair<int,int>>
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int len = queries.size();
        vector<vector<int>>dist(n,vector<int>(m,(int)(1e9)));
        dist[0][0] = grid[0][0];
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,-1,0,1};
        while(!pq.empty()){
            pii p = pq.top();
            pq.pop();
            int val = p.first;
            int x = p.second.first;
            int y = p.second.second;
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]>max(dist[x][y],grid[nx][ny])){
                    dist[nx][ny] = max(dist[x][y],grid[nx][ny]);
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        vector<int>vec;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                vec.push_back(dist[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        vector<int>ans(len);
        for(int i = 0;i < len;i++){
            int idx = lower_bound(vec.begin(),vec.end(),queries[i])-vec.begin();
            ans[i] = idx;
        }
        return ans;
    }
};