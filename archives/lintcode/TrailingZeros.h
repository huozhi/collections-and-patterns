/*
Write an algorithm which computes the number of trailing zeros in n factorial.

样例
11! = 39916800, so the out should be 2

挑战
O(log N) time

标签 Expand 
Mathematics

*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long c = 0, i = 5;
        for (; i <= n; i *= 5) {
            c += n / i;
        }
        return c;
        
    }
};

