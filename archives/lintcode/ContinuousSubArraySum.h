/**

给定一个整数数组，请找出一个连续子数组，使得该子数组的和最大。输出答案时，请分别返回第一个数字和最后一个数字的值。
（如果两个相同的答案，请返回其中任意一个）


样例
给定 [-3, 1, 3, -3, 4], 返回[1,4].


[-3, 1, 3, -3, 4] => [1, 4]

[-101,-33,-44,-55,-67,-78,-101,-33,-44,-55,-67,-78,-100,-200,-1000,-22,-100,-200,-1000,-22] => [15, 15]

[1,2,-2,-100,1,2,-2] => [0, 1]

[1,-1] => [0, 0]

*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> index(2, 0);
        int n = A.size();
        int curSum = 0, maxSum = A[0];
        int s = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                e = i;
                curSum += A[i];
                if (maxSum < curSum) {
                    maxSum = curSum;
                    index[0] = s, index[1] = e;
                }
            }
            else if (curSum + A[i] < 0) {
                if (A[i] > maxSum) {
                    curSum = A[i];
                    maxSum = curSum;
                    index[0] = s, index[1] = e;
                }
                else
                    curSum = 0;
                s = e = i + 1;
            }
            else {
                curSum += A[i];
            }
        }
        return index;
    }
};
