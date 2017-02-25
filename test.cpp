#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

    int expandAroundCenter(const string &s, int i){
        int L = i, R = i, len1 = 1, len2 = 0;
        cout<<"i="<<i<<endl;
        while(L >=0 && R < s.length() && s[L] == s[R]){
            cout<<"L="<<L<<"R="<<R<<endl;
            L--;
            R++;
        }
        len1 = R - L  -1;
        cout<<"len1="<<len1<<endl;
        L = i; R = i + 1;
        while(L >=0 && R < s.length() && s[L--] == s[R++]) len2 += 2;
        int len = len1 > len2 ? len1: len2;
        cout<<"len="<<len<<endl;
        return len;
    }
    string longestPalindrome(string s) {
        int start = 0, size = 0, len = 0;
        for(int i=0; i<s.length(); i++){
            len = expandAroundCenter(s, i);
            if(len <= size) continue;
            start = i - (len-1)/2;
            size = len;
            cout<<"start="<<start<<endl;
            cout<<"len_final="<<len<<endl;
        }

            cout<<"start="<<start<<endl;
            cout<<"len_final="<<len<<endl;
        return s.substr(start, len);
    }

int main(){
    //cout<<longestPalindrome("abada")<<endl;
    cout<<atoi(" +3aa")<<endl;
}
