struct comp{
    bool operator ()(pair<char,int>&a,pair<char,int>&b){
        if(a.first==b.first)
        return a.second<b.second;
        return a.first>b.first;
    }

};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(int i=0;i<s.size();i++){
         if(s[i]=='*')
         {
            pq.pop();
         }
         else{
            pq.push({s[i],i});
         }
        }
        vector<pair<int,char>>v;
        while(pq.size()>0){
        v.push_back({pq.top().second,pq.top().first});
        pq.pop();
        }
        sort(v.begin(),v.end());
        string ans;
        for(auto x:v){
            ans+=x.second;
        }
        return ans;
    }
};