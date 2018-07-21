/**

给你一个包含 m x n 个元素的矩阵 (m 行, n 列), 求该矩阵的之字型遍历。

样例
对于如下矩阵：

[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]
返回 [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> result;
        if (matrix.empty() || matrix.front().empty()) return result;
        int n = matrix.size(), m = matrix.front().size();
        int i = 0, j = 0;
        while (result.size() < n * m) {
            while (i >= 0 && i < n && j >= 0 && j < m) result.push_back(matrix[i--][j++]);
            i++;
            while (i < 0 || j >= m) {
                j--;
                i++;
            }
            while (i >= 0 && i < n && j >= 0 && j < m) result.push_back(matrix[i++][j--]);
            j++;
            while (i >= n || j < 0) {
                i--;
                j++;
            }
        }
        return result;
    }
};
