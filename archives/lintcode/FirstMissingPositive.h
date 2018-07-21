/**

给出一个无序的正数数组，找出其中没有出现的最小正整数。

样例
如果给出 [1,2,0], return 3 如果给出 [3,4,-1,1], return 2

挑战
只允许时间复杂度O(n)的算法，并且只能使用常数级别的空间。

*/

class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int n = A.size();
        for (int i = 0; i < n; ) {
            if (A[i] >= 1 && A[i] <= n) {
                int idx = A[i] - 1;
                if (A[idx] != A[i]) {
                    swap(A[idx], A[i]);
                }
                else
                    i++;
            }
            else
                i++;
        }
        for (int i = 0; i < n; i++)
            if (A[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};