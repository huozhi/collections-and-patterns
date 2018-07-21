/**

给出3*n + 1 个的数字，除其中一个数字之外其他每个数字均出现三次，找到这个数字。

样例
给出 [1,1,2,3,3,3,2,2,4,1] ，返回 4

挑战
一次遍历，常数级的额外空间复杂度

*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int n = A.size();
        int result = 0;

        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] & (1 << i))
                    cnt++;
            }
            result |= ((cnt % 3) << i);
        }
        return result;
    }
};
