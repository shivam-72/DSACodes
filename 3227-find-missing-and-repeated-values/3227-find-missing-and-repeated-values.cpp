class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int r=0,m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=abs(grid[i][j]);
                int id=x-1;
                int row=id/n;
                int col=id%n;
                if(grid[row][col]<0){
                     r=abs(grid[i][j]);
                }
                else{
                    grid[row][col]=-1*grid[row][col];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=grid[i][j];
                if(grid[i][j]>0)
                     m=(i*n+j+1);
            }
        }
        return {r,m};
    }
};