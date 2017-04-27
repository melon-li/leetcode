 //Implement strStr().

 //Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
 
// Accepted with 6ms.
class Solution {
    public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int i = 0, j = 0;
        int m = haystack.length(), n = needle.length();
        for (i = 0; i < m - n + 1; i++) {
            for (j = 0; j < needle.length(); j++){
                if (haystack[i+j] != needle[j]) break;
            }
            if (needle.length() == j) return i;
        }
        return -1;
    }
};


// Accepted with 4ms.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m; ) {
            if (haystack[i] == needle[j]) { 
                i++;
                j++;
            }
            if (j == n) return i - j;
            if (i < m && haystack[i] != needle[j]) {
                if (j) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string& needle) {
        int n = needle.length();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len])
                lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
};
