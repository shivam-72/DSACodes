class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
         vector<int>prev=meetings[0];
         int ans=0;
         if(prev[0]!=0)
          ans = prev[0]-1;
        for(int i=1;i<n;i++){
          if(meetings[i][0]>prev[1]){
            ans+=(meetings[i][0]-prev[1]-1);
            prev=meetings[i];
          }
          else{
            prev[1]=max(prev[1],meetings[i][1]);
          }
        }
        ans+=(days-prev[1]);
        return ans;

    }
};