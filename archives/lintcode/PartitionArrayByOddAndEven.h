/**

分割一个整数数组，使得奇数在前偶数在后。


样例
给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]。

挑战
在原数组中完成，不使用额外空间。

*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return;
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 == 1)
                i++;
            while (i < j && nums[j] % 2 == 0)
                j--;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
    }
};
