class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int res=0;
        for(auto x:words){
            string s=x;
            reverse(s.begin(),s.end());
            if(m[s]>0){
                res+=4;
                m[s]--;
            }
            else
                m[x]++;
        }
        for(auto x:m){
            if(x.first[0]==x.first[1]&&x.second>0)
                return res+2;
        }
        return res;
    }
};