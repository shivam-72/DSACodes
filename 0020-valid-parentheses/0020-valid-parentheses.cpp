class Solution {
public:
    bool match(char a,char b){
        return((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }
    bool isValid(string s) {
        stack<char>s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                s1.push(s[i]);
            }
            else{
                if(s1.empty()==true){
                    return false;
                }
                else if(match(s1.top(),s[i])==false){
                    return false;
                }
                else
                     s1.pop();
            }
        }
        return s1.empty()==true;
    }
};