/*

如果要将整数A转换为B，需要改变多少个bit位？
样例
如把31转换为14，需要改变2个bit位。

(31)10=(11111)2

(14)10=(01110)2

*/


class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        unsigned r = a ^ b, c = 0;
        while (r > 0) {
            c += r & 1;
            r >>= 1;
        }
        return c;    
    }
};
