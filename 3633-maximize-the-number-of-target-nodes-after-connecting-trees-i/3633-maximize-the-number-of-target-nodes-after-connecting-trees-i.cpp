class Solution {
public:
int bfs(int i,map<int,vector<int>>&adj,int k,int N){
    queue<pair<int,int>>q;
    vector<bool>visited(N,false);
    q.push({i,k});
    visited[i]=true;
    int count=0;
    while(!q.empty()){
        int u=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(dist<0){
            continue;
        }
        count++;
        for(auto &ngbr:adj[u]){
            if(!visited[ngbr]){
                visited[ngbr]=true;
                q.push({ngbr,dist-1});
            }
        }

    }
    return count;

}
vector<int> countFound(vector<vector<int>>& edges1,int k){
    int N=edges1.size()+1;
    map<int,vector<int>>adj;
    for(int i=0;i<edges1.size();i++){
        int u=edges1[i][0];
        int v=edges1[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>result(N);
    for(int i=0;i<N;i++){
        result[i]=bfs(i,adj,k,N);
    }
return result;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
       vector<int>result1=countFound(edges1,k);
       vector<int>result2=countFound(edges2,k-1);

       int maxCount=*max_element(begin(result2),end(result2));
       for(int i=0;i<result1.size();i++){
        result1[i]+=maxCount;
       }

return result1;

        
    
}
};