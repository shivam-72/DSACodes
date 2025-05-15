class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        std::vector<string> out;
        out.push_back(words[0]);
        for(int i=1; i< groups.size(); i++){
            if(groups[i]!=groups[i-1]){
                out.push_back(words[i]);
            }
        }
        return out;
    }
};