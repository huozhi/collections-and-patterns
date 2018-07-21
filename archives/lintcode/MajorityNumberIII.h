/**

给定一个整型数组，找到主元素，它在数组中的出现次数严格大于数组元素个数的1/k。

注意
数组中只有唯一的主元素

样例
给出数组 [3,1,2,3,2,3,3,4,4,4] ，和 k = 3，返回 3

挑战
要求时间复杂度为O(n)，空间复杂度为O(k)

*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        map<int, int> m;

        for (int num : nums) {
            if (m.size() < k && m.find(num) == m.end()) {
                m[num] = 1;
            }
            else if (m.find(num) != m.end()) {
                m[num]++;
            }
            else {
                for (auto it = m.begin(); it != m.end(); ) {
                    if (it->second == 1)
                        m.erase(it++);
                    else {
                        it->second--;
                        it++;
                    }
                }
            }
        }
        int max_t = 0, major = m.begin()->first;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > max_t) {
                max_t = it->second;
                major = it->first;
            }
        }
        return major;
    }
};