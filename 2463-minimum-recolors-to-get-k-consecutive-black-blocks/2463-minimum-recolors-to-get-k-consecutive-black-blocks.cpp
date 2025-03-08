class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int n=blocks.size();
        int c1=0,c2=0;
        while(j<n){
          if(blocks[j]=='W'){
            c1++;
          }
          else{
            c2++;
          }
          if(j-i+1==k){
            ans=min(ans,c1);
            if(blocks[i]=='W'){
                c1--;
            }
            else{
                c2--;
            }
            i++;
          }
          j++;
        }
        return ans;
    }
};