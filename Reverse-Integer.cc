//Reverse digits of an integer.

//Example1: x = 123, return 321
//Example2: x = -123, return -321

//click to show spoilers.

//Note:
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 

//@IMPERFECT
class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        do{
            y = x%10 + 10*y;
            x = x/10;
        }while(x);
        if(abs(y) - 0x7ffffffe > 0) return 0;
        return y;
    }
};
