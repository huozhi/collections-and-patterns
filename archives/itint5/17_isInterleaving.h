/**

如果字符串str3能够由str1和str2中的字符按顺序交替形成，那么称str3为str1和str2的交替字符串。例如str1="abc"，str2="def"，那么"adbecf", "abcdef", "abdecf", "abcdef", "adefbc"等等都为str1和str2的交替字符串。更形式化的，str3的生成算法如下：

str3=""
while str1不为空 or str2不为空:
  把str1或str2的首字符加入到str3,并从str1或str2中删除相应的字符
end
给定str1, str2,和str3，判断str3是否为str1和str2的交替字符串。

Solution:
动规，dp[i][j]表示str1中i个字符str2中取j个字符是否能表示str3前i+j个字符

*/

bool isInterleaving(string &str1, string &str2, string &str3) {
    int len1 = str1.length(), len2 = str2.length(), len3 = str3.length();
    if (len1 + len2 != len3) return false;
    bool dp[len1+1][len2+1];
    for (int i = 0; i < len1; i++) {
        dp[i+1][0] = str1[i] == str3[i];
    }
    for (int i = 0; i < len2; i++) {
        dp[0][i+1] = str2[i] == str3[i];
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] =
            dp[i-1][j] && str1[i-1]==str3[i+j-1] ||
            dp[i][j-1] && str2[j-1]==str3[i+j-1];
        }
    }
    return dp[len1][len2];
}
