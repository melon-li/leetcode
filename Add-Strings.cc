//Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

//Note:

    //The length of both num1 and num2 is < 5100.
    //Both num1 and num2 contains only digits 0-9.
    //Both num1 and num2 does not contain any leading zero.
    //You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
    public:
    string addStrings(string num1, string num2) {
        string str = "";
        int len1 = num1.length();
        int len2 = num2.length();
        int len = max(len1, len2);
        int i = 0, ext = 0, re = 0;
        while (i < len) {
            int val1 = i < len1 ? num1[i] : 0;
            int val2 = i < len2 ? num2[i] : 0;
            re = val1 + val2 + ext;
            ext =  re/10;
            string val = re%10 + '0';
            str += val; 
            i++;
        }
        if(ext != 0) str += ext + '0';
        return str;
    }
};
