//Determine whether an integer is a palindrome. Do this without extra space.


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int cur = x, y = 0;
        while(cur){
            y = y*10 + cur%10;
            cur = cur/10;
        }
        if(y == x) return true;
        return false;
    }
};
