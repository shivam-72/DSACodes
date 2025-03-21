class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>&ing, vector<string>& supplies)     {
        queue<string>q;
        for(auto s:supplies)
            q.push(s);
        unordered_map<string,int>deg;
        unordered_map<string,vector<string>>adj;
        int n=recipes.size();
        unordered_map<string,bool>inRecipes;
        for(int i=0;i<n;i++)
        {
            inRecipes[recipes[i]]=true;
            deg[recipes[i]]=ing[i].size();
            for(auto &in:ing[i])
            {
                adj[in].push_back(recipes[i]);
            }
        }
        vector<string>res;
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(inRecipes[s])
                res.push_back(s);
            for(auto &t:adj[s])
            {
                deg[t]--;
                if(deg[t]==0)
                    q.push(t);
            }
        }
        return res;
    }
};