/**

给出两个字符串，找到最长公共子串，并返回其长度。



样例
给出A=“ABCD”，B=“CBCE”，返回 2

注意
子串的字符应该连续的出现在原字符串中，这与子序列有所不同。

*/


class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if (A.empty() || B.empty()) return 0;
        int ls = A.length(), lt = B.length();
        int dp[ls][lt];
        int maxlen = 0;
        for (int i = 0; i < ls; i++) {
            dp[i][0] = (A[i] == B[0]);
            maxlen = max(maxlen, dp[i][0]);
        }
        for (int j = 0; j < lt; j++) {
            dp[0][j] = (A[0] == B[j]);
            maxlen = max(maxlen, dp[0][j]);
        }

        for (int i = 1; i < ls; i++) {
            for (int j = 1; j < lt; j++) {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0; // consecutive
                maxlen = max(maxlen, dp[i][j]);
            }
        }

        return maxlen;
    }
};