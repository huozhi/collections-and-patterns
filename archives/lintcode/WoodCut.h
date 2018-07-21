/*

中等 木材加工 查看运行结果 提交历史

20% 通过
有一些原木，现在想把这些木头切割成一些长度相同的小段木头，需要得到的小段的数目至少为k。
当然，我们希望得到的小段越长越好，你需要计算能够得到的小段木头的最大长度。



注意
木头长度的单位是厘米。原木的长度都是正整数，我们要求切割得到的小段木头的长度也要求是整数。无法切出要求至少k段的,则返回0即可。

样例
例如: L=[232, 124, 456], k=7, return 114.

挑战
O(n log Len), Len为n段原木中最大的长度

标签 Expand 
二分法

*/

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.empty() || k == 0) return 0;
        int mid,
            r = 0,
            low = 1,
            high = *std::max_element(L.begin(), L.end());

        while (low <= high) {
            int parts = 0;
            mid = low + (high - low) / 2;
            for (int l : L) parts += (l / mid);
            if (parts < k) {
                high = mid - 1;
            }
            else {
                r = mid;
                low = mid + 1;
            }
        }
        return r;
    }
};