class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>u;
        unordered_map<string,vector<string>>graph;
        unordered_map<string,int>indegree;
        int n=supplies.size();
        for(int i=0;i<n;i++){
            u.insert(supplies[i]);
        }  
        for(auto x : recipes)indegree[x] = 0; 

        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
              if(u.count(ingredients[i][j])==0){
                graph[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
              }
            }
        }
       queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto x: graph[tmp]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }
};