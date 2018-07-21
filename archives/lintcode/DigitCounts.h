/**
计算数字k在0到n中的出现的次数，k可能是0~9的一个值

样例
例如n=12，k=1，在 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，我们发现1出现了5次 (1, 10, 11, 12)

153 6 
15 - 1 = 14, 6

*/



class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        /**
            split a digit into 2 parts
            for example
            1234     5
             ^       ^
           higher  lower
           then count the current position number
           which is the last of the higher position
        */

        int low, // lower order position
            high, // higher order position
            cur, // current position
            base = 1,
            c = 0;
        if (n == 0 && k == 0) return 1;
        while (n / base > 0) {
            cur = (n / base) % 10;
            low = n - (n / base) * base;
            high = n / (base * 10);

            if (cur < k) {
                c += high * base;
            }
            else if (cur == k) {
                c += high * base + low + 1;
            }
            else {
                c += (high + 1) * base;
            }
            base *= 10;
        }
        return c;
    }
};