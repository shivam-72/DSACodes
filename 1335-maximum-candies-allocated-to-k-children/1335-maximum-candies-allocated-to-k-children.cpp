class Solution {
public:
int solve(vector<int>& candies, long long k,int mid){
     long long c=0;
       for(int i=0;i<candies.size();i++){
           c+=(candies[i]/mid);
           if(c>=k)
           return true;
       }
       return false;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int i=1;
        int j=*max_element(candies.begin(),candies.end());
        while(i<=j){
            int mid=(i+j)/2;
            if(solve(candies,k,mid))
            i=mid+1;
            else
            j=mid-1;
        }
        return j;
    }
};