class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i= low; i<=high; i++){
            string num = to_string(i);
            int len = num.length();
            if(len%2 == 0){
                int s = 0, e = 0;
                for(int i=0; i<len/2; i++){
                    s += int(num[i]);
                    e += int(num[len - i -1]);
                }
                if(s==e) cnt++;
            }
        }
        return cnt;
    }
};