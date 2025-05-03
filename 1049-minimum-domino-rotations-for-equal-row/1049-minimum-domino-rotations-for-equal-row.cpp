class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int top[7]={0};
        int bottom[7]={0};
        int same[7]={0};
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            bottom[bottoms[i]]++;
            top[tops[i]]++;
            if(tops[i]==bottoms[i]){
                same[tops[i]]++;
            }
        }
        for(int i=1;i<7;i++){
            if(top[i]+bottom[i]-same[i]==n)
                ans=min(ans,min(top[i],bottom[i])-same[i]);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};