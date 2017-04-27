// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
// Example:
//Given a = 1 and b = 2, return 3. 
#include <iostream>
using namespace std;

class Solution {
    public:
    int getSum(int a, int b) {
        bool cur = 0, ext = 0;
        int re = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            if (a >> i & 1) cnt++;
            if (b >> i & 1) cnt++;
            if (ext) cnt++;
            ext = cnt >= 2 ? 1 : 0;
            cur = cnt%2 == 1 ? 1 : 0;
            re |= cur << i;
        }
        return re;
    }
};

int main() {
    Solution s;
    std::cout<<s.getSum(2, 3)<<endl;
}
