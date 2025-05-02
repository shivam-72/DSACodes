class Solution {
public:
    string pushDominoes(string dominoes) {
       int n=dominoes.size();
        vector<int>left(n,0),right(n,0);
        char prev='.';
        int count=1;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                prev='R';
                count=1;
                continue;
            }
            else if(dominoes[i]=='L'){
                prev='L';
            }
            else if(prev=='R'&&dominoes[i]=='.'){
                right[i]=count;
                count++;
            }
        }
        count=1;
        prev='.';
        string ans;
         for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prev='L';
                count=1;
                continue;
            }
            else if(dominoes[i]=='R'){
                prev='R';
            }
            else if(prev=='L'&&dominoes[i]=='.'){
                left[i]=count;
                count++;
            }
           
        }
        for(int i=0;i<n;i++){
          if(left[i]==0&&right[i]==0)
              ans+=dominoes[i];
          else if(left[i]==right[i])
              ans+='.';
        else if(left[i]==0)
                ans+='R';

        else if(right[i]==0)
                ans+='L';
        else if(left[i]>right[i])
                 ans+='R';
             else
                 ans+='L';
        }
        return ans;
        
    }
};