class Solution {
public:
    int numTilings(int n) {
        if(n==1||n==2)
        return n;
        int m=1e9+7;
        vector<long long>v(n+1,1);
        v[2]=2;
        for(int i=3;i<=n;i++){
          v[i]=((2*v[i-1])%m+(v[i-3])%m)%m;
        }
        return v[n];
    }
};