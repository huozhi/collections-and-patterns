/*

Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.

样例
For A=[1, 2, 3], B is [6, 3, 2]

标签 Expand 
Forward-Backward Traversal LintCode Copyright

*/


class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result;
        if (nums.size() == 1) return result;
        vector<long long> suffix(nums.size() + 1);
        long long v;

        suffix[nums.size()] = 1;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            // v *= nums[i];
            suffix[i] = suffix[i + 1] * nums[i];
            // = v;
        }

        long long prefix = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            result.push_back(prefix * suffix[i + 1]);
            prefix *= nums[i];
        }
        return result;
    }
};