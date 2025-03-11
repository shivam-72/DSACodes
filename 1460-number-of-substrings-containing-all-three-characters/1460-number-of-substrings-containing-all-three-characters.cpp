class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int c1=0;
        int c2=0;
        int c3=0;
        int i=0;
        int j=0;
        long long ans=0;
        while(j<n){
            if(s[j]=='a'){
                c1++;
            }
            else if(s[j]=='b'){
                c2++;
            }
            else{
                c3++;
            }
            while(c1>=1&&c2>=1&&c3>=1){
                if(s[i]=='a'){
                    c1--;
                }
                 else if(s[i]=='b'){
                c2--;
            }
            else{
                c3--;
            }
              ans+=(n-j);
              i++;
            }
            j++;
        }
        return ans;
    }
};