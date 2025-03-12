class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int e1=m-1;
       int e2=n-1;
       int end=m+n-1;
       while(e2>=0){
          if(e1>=0&&nums1[e1]>nums2[e2]){
            nums1[end]=nums1[e1];
            e1--;
          }
          else if(e1>=0&&nums1[e1]<nums2[e2]){
            nums1[end]=nums2[e2];
            e2--;
          }
          else{
            nums1[end]=nums2[e2];
            e2--;
          } 
          end--;
       } 
       
    }
};