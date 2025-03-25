class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> arr;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(end>s){
                end=max(end,e);
            }
            else{
                arr.push_back({start,end});
                start=s;
                end=e;
            }
        }
        arr.push_back({start,end});
        return arr;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> a;
        vector<vector<int>> b;
        for(auto it:rectangles){
            a.push_back({it[0],it[2]});
            b.push_back({it[1],it[3]});
        }
        vector<vector<int>> r1=merge(a);
        vector<vector<int>> r2=merge(b);
        return ((r1.size()>=3)||(r2.size()>=3));
    }
};