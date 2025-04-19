class Solution {
public:
    void solve(string &s,int n){
        if(n==1){
            return;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int cnt=0;
          while(i<s.size()&&s[i]==c){
            i++;
            cnt++;
          }
          i--;
          ans+=to_string(cnt);
          ans+=c;
        }
        s=ans;
        solve(s,n-1);
    }
    string countAndSay(int n) {
        if(n==1)
        return "1";
        string s="1";
        solve(s,n);
        return s;
    }
};