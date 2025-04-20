class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0){
                ans++;
                continue;
            }
            if(m.find(answers[i])!=m.end()){
                m[answers[i]]--;
                if(m[answers[i]]==0)
                m.erase(answers[i]);
                ans++;
            }
            else{
             m[answers[i]]=answers[i];
             ans++;
            }
        }
        for(auto x:m){
            ans+=x.second;
        }
        return ans;
    }
};