class Solution {
public:
    vector<int> combinations;
    int mod = 1e9+ 7;

    int dp[50][1000 + 2];


    void comb(int num, int index, int m) {
        if (index == m) {
            combinations.push_back(num);
            return;
        }

        int last = num % 10;
        
        for (int i = 1; i <= 3; i++) {
            if(last != i){
                num = num * 10 + i;
                comb(num, index + 1 , m);
                num /= 10;
            }
        }

        return;
    }

    bool check(int num1, int num2){
        while(num1 > 0 && num2 > 0){
            if((num1 % 10) == (num2 % 10)){
                return false;
            }
            num1 /= 10;
            num2 /= 10;
        }

        return num1 == 0 && num2 == 0;
    }

    int rec(int indexFromComb, int index, int &n){
        if(index == n){
            return 1;
        }

        if(dp[indexFromComb][index] != -1 ){
            return dp[indexFromComb][index];
        }
        
        int num = combinations[indexFromComb];

        long long ans = 0;

        for(int i = 0; i < combinations.size(); i++){
            if(check(num , combinations[i]) || index == 0){
                ans = (ans + rec(i, index + 1, n))%mod;
            }
        }
 
        return dp[indexFromComb][index] = ans;
    }

    int colorTheGrid(int m, int n) {
        comb(0, 0, m);

        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 1e3 + 2; j++){
                dp[i][j] = -1;
            }
        }

        
        return rec(0, 0, n);
    }
};