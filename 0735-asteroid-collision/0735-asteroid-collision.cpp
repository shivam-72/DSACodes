class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>s;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                s.push(asteroids[i]);
            }
            else{
                while(s.size()>0&&s.top()<abs(asteroids[i])&&s.top()>0){
                    s.pop();
                }
                if(s.size()>0&&s.top()==abs(asteroids[i])){
                    s.pop();
                    continue;
                }
                if(s.size()==0||(s.size()>0&&s.top()<0)){
                    s.push(asteroids[i]);
                }
            }
        }
        vector<int>v;
        while(s.size()>0){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
      
        return v;
    }
};