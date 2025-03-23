class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        int mx=0;
        for(int i=0;i<n;i++){
          if(s.size()==0||heights[s.top()]<heights[i]){
             s.push(i);
          }
          else{
             while(s.size()>0&&heights[i]<=heights[s.top()]){
                int nsr=i;
                int c=heights[s.top()];
                s.pop();
                int nsl=-1;
                if(s.size()!=0){
                   nsl=s.top();
                }
                mx=max(mx,(nsr-nsl-1)*c);
             }
             s.push(i);
          }
        }
         while(s.size()>0){
            int nsr=n;
            int c=heights[s.top()];
                s.pop();
            int nsl=-1;
                if(s.size()!=0){
                   nsl=s.top();
                }
            mx=max(mx,(nsr-nsl-1)*c);
        }
        return mx;
    }
};