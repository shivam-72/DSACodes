class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mapp;
        vector<int>ans;
        for(int digit:digits){
            mapp[digit]++;
        }
        int num =100;
        for(num;num<=998;num+=2){
            int digit1=num/100;
            int digit2=(num/10)%10;
            int digit3=num%10;
            vector<int>count(10,0);
            count[digit1]++;
            count[digit2]++;
            count[digit3]++;
            if(count[digit1]<=mapp[digit1]&&count[digit2]<=mapp[digit2]&&count[digit3]<=mapp[digit3])
               ans.push_back(num);
            continue;   
        }
        return ans;
    }
};