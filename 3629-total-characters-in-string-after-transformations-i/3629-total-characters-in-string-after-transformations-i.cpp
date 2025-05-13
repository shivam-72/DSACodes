class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
      map<char,int>f;
      for(auto&it:s)f[it]++;
      int mod =1e9+7;
      for(int  i=0;i<t;i++){
        int z=f['z']%mod;
        for(char ch='y';ch>='a';ch--){
            f[ch+1]=f[ch]%mod;
        }
        f['a']=z;f['b'] =(f['b']+z)%mod;
      }
        long long sum=0;
        for(auto &[u,v]:f){
            sum+=v%mod;
            sum%=mod;
        }
        return (int)sum%mod;
      
    }
};