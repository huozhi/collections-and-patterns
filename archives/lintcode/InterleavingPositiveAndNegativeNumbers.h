/**

给出一个含有正整数和负整数的数组，重新排列成一个正负数交错的数组。

注意
不需要保持正整数或者负整数原来的顺序。

样例
给出数组[-1, -2, -3, 4, 5, 6]，重新排序之后，变成 [-1, 5, -2, 4, -3, 6]或者其他任何满足要求的答案

挑战
原地完成，没有额外的空间

*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        bool isOdd = (A.size() % 2 == 0) ? false : true,
             positive = true;
        int cntPos = 0, cntNeg = 0;
        if (isOdd) {
            for (unsigned i = 0; i < A.size(); i++)
                (A[i] > 0) ? cntPos++ : cntNeg++;
            
            if (cntPos < cntNeg) positive = false;
            int sign = positive ? 1 : -1;
            moveToEnd(A, sign);
        }
        rerangeBetween(A, positive);
        return A;
    }

    void rerangeBetween(vector<int> &A, bool positive) {
        int n = A.size() / 2 * 2,
            i = 0,
            j = 1;

        for (; i < n - 1; i += 2) {
            if (A[i] < 0) {
                for (; j < n; j += 2) {
                    if (A[j] > 0) {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
        }
        if (!positive) reverse(A.begin(), A.end() - 1);
    }

    void moveToEnd(vector<int> &A, int sign) {
        int last = (int)A.size() - 1, idx = 0;
        for (int i = 0; i < A.size(); i++) {
            if (sign * A[i] > 0) {
                idx = i;
                break;
            }
        }
        swap(A[idx], A[last]);
    }
};