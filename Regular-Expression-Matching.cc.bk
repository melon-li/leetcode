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

class Solution {
public:
    bool isMatch(string s, string p) {
        int pos = p.find("*");
        string pfront, sfront;
        while (pos >= 0) {
            if (pos == 0) {
                p = p.substr(1);
                pos = p.find("*");
                continue;
            } else if (pos >= 2) {
                if (s.length() < (pos - 1)) return false;
                pfront = p.substr(0, pos - 1);
                sfront = s.substr(0, pos - 1);
                if (!isMatchFront(sfront, pfront)) return false;
                s = s.substr(pos - 1);
                p = p.substr(pos - 1);
            }
             if (!isMatchBack(s, p)) return false;
             pos = p.find("*");
        }
        return isMatchFront(s, p);
    }

    bool isMatchBack(string &s, string &p){
        char key = p[0], edge; 
        int i = 0, j = 2;
        if (key == '.') key = s[0];
        if (key != s[0]){
            p = p.substr(2);
            return true;
        }
        if (p.length() <= 2){
            if( p[0] == '.'){
                p = s = "";
                return true;
            }
            for (i = 0; i < s.length(); i++)
                if (s[i] != key) return false;
            p = s = "";
            return true;
        }

        for (j=2; j < p.length(); j++){
            if (p[j] == '*') continue;
            if (p[j] != key) break;
        }
        if (j >= p.length()) {
            if (p[0] == '.'){
                p = s = "";
                return true;
            }
            for (i = 0; i < s.length(); i++)
                if (s[i] != key) return false;
            p = s = "";
            return true;
        }
        edge = p[j];

        for (i = 0; i < s.length(); i++) {
            if (key == s[i]) continue;
            if (edge == s[i]) break;
        }
        if (i >= s.length()) return false;
        s = s.substr(i);
        p = p.substr(j);
        return true;
    }

    bool isMatchFront(string s, string p) {
        int pos = 0;
        string pfront, sfront;
        if (s.length() != p.length()) return false;
        if (p.find(".") < 0) {
            if (s != p) return false;
            return true;
        }
        pos = p.find(".");
        while (pos >= 0) {
            pfront = p.substr(0, pos);
            sfront = s.substr(0, pos);
            if (pfront != sfront) return false;
            p = p.substr(pos + 1);
            s = s.substr(pos + 1);
            pos = p.find(".");
        }
        if (s != p) return false;
        return true;
    }
};
