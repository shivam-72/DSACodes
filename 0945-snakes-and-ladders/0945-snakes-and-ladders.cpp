class Solution {
public:
   pair<int,int> coordinates(int x,int n){
      int r=n-(x-1)/n-1;
       int c=(x-1)%n;
       if(r%2==n%2)
       return {r,n-c-1};
       return {r,c};
   }
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
        queue<int>q;
        q.push(1);
        int n=board.size();
        vector<vector<bool>>v(n,vector<bool>(n,false));
        v[n-1][0]=true;
        while(q.size()>0){
            int c=q.size();
            for(int i=0;i<c;i++){
                int x=q.front();
                if(x==n*n)
                return steps;
                q.pop();
                for(int j=1;j<=6;j++){
                   if(j+x>n*n)
                   break;
                   auto p=coordinates(x+j,n);
                   if(v[p.first][p.second])
                   continue;
                   v[p.first][p.second]=true;
                   if(board[p.first][p.second]!=-1)
                   q.push(board[p.first][p.second]);
                   else
                   q.push(j+x);
                }
            }
            steps++;
        }
        return -1;
    }
};