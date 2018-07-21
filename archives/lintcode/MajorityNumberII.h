/*

Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.

Find it.

注意
There is only one majority number in the array

样例
For [1, 2, 1, 2, 1, 3, 3] return 1

挑战
O(n) time and O(1) space

标签 Expand 
Greedy Enumeration LintCode Copyright

*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if (nums.empty()) return -1;
        if (nums.size() <= 2) return nums[0];
        int major1 = nums[0], major2;
        int pcnt = 0;

        while (pcnt < nums.size() && major1 == nums[pcnt])
            ++pcnt;

        if (pcnt == nums.size()) return major1;
        major2 = nums[pcnt];
        int cnt1 = pcnt, cnt2 = 1;
        for (int i = pcnt + 1; i < nums.size(); i++) {
            if (major1 == nums[i]) {
                ++cnt1;
            }
            else if (major2 == nums[i]) {
                ++cnt2;
            }
            else {
                // replace or reduce counter
                if (cnt1 == 0) {
                    major1 = nums[i];
                    ++cnt1;
                }
                else if (cnt2 == 0) {
                    major2 = nums[i];
                    ++cnt2;
                }
                else {
                    --cnt1; --cnt2;
                }
            }
        }
        if (!cnt1 && !cnt2) return -1;
        else if (!cnt1) {
            return major2;
        }
        else if (!cnt2) {
            return major1;
        }
        else {
            int tmp = 0;
            for (int i = 0; i < nums.size(); i++)
                tmp += (nums[i] == major1);
            if (tmp > nums.size() / 3)
                return major1;
            return major2;
        }
    }
};