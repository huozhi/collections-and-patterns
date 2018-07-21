/**

实现赋值运算符重载函数，确保：

新的数据可准确地被复制
旧的数据可准确地删除/释放
可进行 A = B = C 赋值
样例
如果进行 A = B 赋值，则 A 中的数据被删除，取而代之的是 B 中的数据。

如果进行 A = B = C 赋值，则 A 和 B 都复制了 C 中的数据。

挑战
充分考虑安全问题，并注意释放旧数据。

*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (m_pData == object.m_pData)
            return *this;
        if (m_pData != NULL) {
            delete [] m_pData;
            m_pData = NULL;
        }
        // because the problem of lintcode oj, we must write '!= NULL' here, not other format
        if (object.m_pData != NULL) {
            int len = strlen(object.m_pData);
            m_pData = new char[len + 1];
            strcpy(m_pData, object.m_pData);
        }
        return *this;
    }
};
