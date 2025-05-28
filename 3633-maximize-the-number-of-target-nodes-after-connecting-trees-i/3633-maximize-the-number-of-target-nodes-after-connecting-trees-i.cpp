class Solution {
public:
    
    unordered_map<int,vector<int>> bulidTree(vector<vector<int>>& edges){

        unordered_map<int,vector<int>> tree;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        return tree;
    }

    int  dfs(unordered_map<int,vector<int>>& tree, int u, int k, int parent) {

        if(k < 0){
            return 0;
        }
        int count = 1;

        for(int& v : tree[u]){
            if(v != parent){
                count += dfs(tree,v,k-1,u);
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        unordered_map<int,vector<int>> tree1 = bulidTree(edges1);
        unordered_map<int,vector<int>> tree2 = bulidTree(edges2);
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        int maxi = 0;
        vector<int> ans1(n,0);
        vector<int> ans2(m,0);
        
        for(int i=0; i<n; i++){
            ans1[i] = dfs(tree1,i,k, -1);
        }
        for(int i=0; i<m; i++){
            ans2[i] = dfs(tree2,i,k-1,-1);
            maxi = max(maxi,ans2[i]);
        }
        for(int i=0; i<n; i++){
            ans1[i] = ans1[i] + maxi;
        }
        return ans1;
    }
};