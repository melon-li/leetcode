//Given a roman numeral, convert it to an integer.

//Input is guaranteed to be within the range from 1 to 3999.
#include <iostream>
using namespace std;

class Solution {
    public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') num += 1;
            if (s[i] == 'V') num += 5;
            if (s[i] == 'X') num += 10;
            if (s[i] == 'L') num += 50;
            if (s[i] == 'C') num += 100;
            if (s[i] == 'D' ) num += 500;
            if (s[i] == 'M') num += 1000;
            if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) num -= 2;
            if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) num -= 20;
            if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) num -= 200;
        }
        return num;
    }
};

int main(){
    string s = "MCMXCVI";
    Solution S;
    cout<<S.romanToInt(s)<<endl;
}
