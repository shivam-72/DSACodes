class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==right){
            return {-1,-1};
        }
       
        vector<bool>v(right+1,true);
         v[0]=false;
        v[1]=false;
        for(int i=2;i*i<=right;i++){
            if(v[i]){
         for(int j=i*i;j<=right;j=j+i){
           v[j]=false;
         }
            }
        }
        int a=-1;
        int mn=INT_MAX;
        int n1=-1;
        int n2=-1;
        for(int i=left;i<=right;i++){
         if(v[i]){
         if(a==-1){
          a=i;
         }
         else{
          if(mn>i-a){
            mn=i-a;
            n1=a;
            n2=i;
          }
          a=i;
         }
         }
        }
        return {n1,n2};
    }
};