/**

用递归的方法找到从1到最大的N位整数。

样例
给出 N = 1, 返回[1,2,3,4,5,6,7,8,9].

给出 N = 2, 返回[1,2,3,4,5,6,7,8,9,10,11,...,99].

注意
用下面这种方式去递归其实很容易：

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
但是这种方式会耗费很多的递归空间，导致堆栈溢出。你能够用其他的方式来递归使得递归的深度最多只有 N 层么？

挑战
用递归完成，而非循环的方式。



*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;//(1, 0);
        recursion(n, result);
        return result;
    }

    void recursion(int n, vector<int>& result) {
        if (n == 0)
            return;
        recursion(n - 1, result);
        int i = result.empty() ? 0 : pow(10, n - 2);
        int last = result.empty() ? 0 : result.back();
        for (; i <= last; i++) {
            int j = i == 0 ? 1 : 0;
            for (; j <= 9; j++)
                result.push_back(i * 10 + j);
        }
    }
};