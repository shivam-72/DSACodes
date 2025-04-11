class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>bfsQueue;
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
           bfsQueue.push({i,j});
           vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int freshorange=cnt;
        int time=0;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(bfsQueue.size()>0){
         int curr_size=bfsQueue.size();
         while(curr_size--){
           auto x=bfsQueue.front();
           bfsQueue.pop();
          for(auto direction:dir)
          {
            int nx=direction[0]+x.first;
            int ny=direction[1]+x.second;
            if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]==0||vis[nx][ny]==1)
            continue;
            bfsQueue.push({nx,ny});
            freshorange--;
            vis[nx][ny]=1;
          }
         }
         if(bfsQueue.size()>0)
         time++;
        }
        if(freshorange==0)
        return time;
        return -1;
    }
};