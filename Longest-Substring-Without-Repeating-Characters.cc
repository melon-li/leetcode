//Given a string, find the length of the longest substring without repeating characters.

//Examples:

//Given "abcabcbb", the answer is "abc", which the length is 3.

//Given "bbbbb", the answer is "b", with the length of 1.

//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> substr;
        int ans = 0;
        for(int i=0,j=0; j<s.length(); j++){
            if(substr.find(s[j]) != substr.end()){
                i = max(substr[s[j]]+1, i);
            }
            substr[s[j]] = j;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
