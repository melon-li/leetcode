//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

//Example:

//Input: "babad"

//Output: "bab"

//Note: "aba" is also a valid answer.

//Example:

//Input: "cbbd"

//Output: "bb"



class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, size = 0, len = 0;
        for(int i=0; i<s.length(); i++){
            len = expandAroundCenter(s, i);
            if(len <= size) continue;
            start = i - (len-1)/2;
            size = len;
        }
        return s.substr(start, size);
    }

private:
    int expandAroundCenter(const string &s, int i){
        int L = i, R = i, len1 = 1, len2 = 0;
        while(--L >=0 && ++R < s.length() && s[L] == s[R]) len1 += 2;
        L = i; R = i + 1;
        while(L >=0 && R < s.length() && s[L--] == s[R++]) len2 += 2;
        int len = len1 > len2 ? len1: len2;
        return len;
    }
    
};
