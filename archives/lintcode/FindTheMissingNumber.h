/**

给出一个包含 0 .. N 中 N 个数的序列，找出0 .. N 中没有出现在序列中的那个数。

样例
N = 4 且序列为 [0, 1, 3] 时，缺失的数为2。

注意
可以改变序列中数的位置。

挑战
在数组上原地完成，使用O(1)的额外空间和O(N)的时间。

*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] != i
                && nums[i] >= 0 && nums[i] < n
                && nums[ nums[i] ] != nums[i]) {
                    swap(nums[i], nums[ nums[i] ]);
            }
            else
                i++;
        }
        for (i = 0; i < n; i++)
            if (nums[i] != i) return i;
        return nums.back() + 1;
    }
};
