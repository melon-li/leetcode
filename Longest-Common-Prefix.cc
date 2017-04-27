//Write a function to find the longest common prefix string amongst an array of strings. 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int cur = 0;
        while(1){
            if (strs.empty()) return prefix;
            for(int i = 0; i < strs.size(); i++){
                if (cur >= strs[i].length()) return prefix;
                if (i == strs.length() - 1) break;
                if (strs[i][cur] != strs[i+1][cur]) return prefix;
            }
            prefix += strs[i][cur++];
        }
        return prefix;
    }
};
