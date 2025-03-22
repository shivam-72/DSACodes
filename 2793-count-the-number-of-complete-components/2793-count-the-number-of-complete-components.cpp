class Solution {
public:
int cnt=0;
 void solve(int i,vector<vector<int>>&graph,vector<int>&vis,vector<int>&v){
        vis[i]=1;
        v.push_back(i);
        for(auto x:graph[i]){
            if(vis[x]==0){
                solve(x,graph,vis,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>inde(n,0);
        for(int i=0;i<edges.size();i++){
         graph[edges[i][0]].push_back(edges[i][1]);
         graph[edges[i][1]].push_back(edges[i][0]);
         inde[edges[i][0]]++;
         inde[edges[i][1]]++;
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt=0;
                vector<int>v1;
          solve(i,graph,vis,v1);
          int k=1;
          for(auto x:v1){
            if(inde[x]!=v1.size()-1)
            k=0;
          }
          if(k)
          ans++;
            }
        }
        return ans;
    }
};