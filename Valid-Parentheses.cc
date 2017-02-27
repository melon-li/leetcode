// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// The brackets must close in the correct order, '()' and '()[]{}' are all valid
// but '(]' and '([)]' are not'))'

class Solution {
public:
    bool isValid(string s) {
        stack<char> left_chars;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left_chars.push(s[i]);
            if (s[i] == '{') left_chars.push(s[i]);
            if (s[i] == '[') left_chars.push(s[i]);
            if (s[i] == ')') {
                if (left_chars.empty() || left_chars.top() != '(') return false;
                left_chars.pop();
            }
            if (s[i] == '}') {
                if (left_chars.empty() || left_chars.top() != '{') return false;
                left_chars.pop();
            }
            if (s[i] == ']') {
                if (left_chars.empty() || left_chars.top() != '[') return false;
                left_chars.pop();
            }
        }
        if (!left_chars.empty()) return false;
        return true;
    }
};
