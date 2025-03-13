class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        vector<int>id(numCourses,0);
        for(auto x: prerequisites){
            v[x[1]].push_back(x[0]);
            id[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(q.size()>0){
            int t=q.front();
            c++;
            q.pop();
           for(auto x:v[t]){
               id[x]--;
               if(id[x]==0){
                q.push(x);
               }
           }
        }
        return numCourses==c;
    }
};