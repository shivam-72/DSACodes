class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
        return word;
        char x=word[0];;
        int st=0;
        int n=word.size();
        vector<int>v;
        for(int i=0;i<word.size();i++){
               if(x<word[i]){
                  x=word[i];
               }     
        }
        for(int i=0;i<word.size();i++){
               if(x==word[i]){
                 v.push_back(i);
               }     
        }
      string str(1, x);
       if(word.size()==numFriends)
           return str;
           string mx="";
        for(int i=0;i<v.size();i++){
            int totallen=n-v[i];
            int num=numFriends;
              num-=v[i];
            int len=totallen-(num-1);
            if(mx==""){
                mx=word.substr(v[i],len);
            }
            else
            mx=max(mx,word.substr(v[i],len));
        }
        return mx;
    }
};