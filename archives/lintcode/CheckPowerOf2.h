/*

Check Power of 2

Using O(1) time to check whether an integer n is a power of 2.

样例
For n=4, return true

For n=5, return false

挑战
O(1) time

标签 Expand 
Binary

*/


class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return n && !(n & ((long long)n - 1));
    }
};
