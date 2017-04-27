// Implement regular expression matching with support for '.' and '*'.

//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

//This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

    //P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    //P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
    //P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

//Putting these together, we will have the following code.

// Dynamic Programing
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1] = {{false}};
        dp[0][0] = true;
        for (int i = 0; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                if ('*' == p[j-1]){
                    dp[i][j] = (s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j-2] 
                               || dp[i][j-2]
                } else {
                    dp[i][j] =  i > 0 
                                && (s[i-1] == p[j-1] || p[j-1] == '.')
                                && dp[i-1][j-1]
                }
            }
        }
    }
};


// Recursive algorithm
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) 
                    || !s.empty() && (s[0] == p[0] || '.' == p[0]) 
                                  && isMatch(s.substr(1), p));
        else
            return !s.empty() 
                   && (s[0] == p[0] || '.' == p[0]) 
                   && isMatch(s.substr(1), p.substr(1));
    }
};
