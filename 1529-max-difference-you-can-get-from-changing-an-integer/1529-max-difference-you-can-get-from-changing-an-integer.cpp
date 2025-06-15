class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);

        char chMax = 0;
        char chMin = temp[0];
        string MaxString;
        string MinString;
        bool check = false;

        if(chMin ==  '1'){
            
            for(int i = 1; i < temp.size(); i++){
                if(temp[i] != '0' && temp[i] != '1') {
                    check = true;
                    chMin = temp[i];
                    break;}
            }

        }

        for(char i : temp) if(i != '9') {chMax = i;break;}

        if(chMax){
            for(char i : temp) MaxString.push_back( i == chMax ? '9' : i);
        }else{
            MaxString = temp;
        }

        for(char i : temp) MinString.push_back( i == chMin ? (!check) ? '1': '0': i);
        
        return stoi(MaxString) - stoi(MinString);
    }
};