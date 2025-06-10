class Solution {
public:
    int maxDifference(string s) {
       vector<int>freq(26,0);
       int mx1=INT_MIN;
       int mx2=INT_MIN;
       for(auto x:s){
        freq[x-'a']++;
       }
       for(auto x:freq){
        if(x%2!=0){
          mx1=max(mx1, x);
        }
       } 
         for(auto x:freq){
        if(x%2==0&&x!=0)
        mx2=max(mx2,mx1-x);
       } 
       return mx2;
    }
};