class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>graph(n);
        for(auto x:roads){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        vector<long long>dist(n,LONG_MAX);
        int mod=1e9+7;
        vector<long long>ans(n,0);
        dist[0]=0;
        ans[0]=1;
        while(pq.size()>0){
           pair<long long ,long long> x=pq.top();
            long long dis=x.first;
            long long node=x.second;
            pq.pop();
            if(dis>dist[node])
            continue;
            for(auto x:graph[node]){
                if(dis+x.second<dist[x.first]){
                   dist[x.first]=dis+x.second;
                   ans[x.first]=ans[node];
                   pq.push({dist[x.first],x.first});
                }
                else if((dis+x.second)==dist[x.first]){
                  ans[x.first]=(ans[node]+ans[x.first])%mod;
                }
            }
        }
        return ans[n-1];

    }
};