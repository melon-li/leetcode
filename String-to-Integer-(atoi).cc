//Implement atoi to convert a string to an integer.

//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. 


//IMPERFECT ***
class Solution {
public:
    int myAtoi(string str) {
        long re = 0;
        bool flag = true;
        int sign = 1;
        for(int i=0; i<str.length(); i++){
            if(flag){
                if(str[i] == ' ') continue;
                if(str[i] == '+'){flag=false; continue;}
                if(str[i] == '-'){flag=false; sign = -1;continue;}
            }
            if(str[i] <  '0' || str[i] > '9') break;
            re = (str[i] - '0') + 10*re;
            flag = false;
            if(sign == 1 && re > 0x7fffffff) {re = 0x7fffffff; break;}
            if(sign == -1 && re> 0x7fffffff){ re = 0x7fffffff + 1; break;}
        }

        return re*sign;
    }
};
