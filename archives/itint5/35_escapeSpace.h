/**
请将字符串str中的空格全部转换为"%20"，str有足够的空间可以存放转换后的结果。

提示：不要使用任何辅助空间
*/

void escapeSpace(char *str) {
    if (!str) return;
    int cnt = 0, len = strlen(str);
    char *p = str;

    while (*p) {
        if (*p == ' ') ++cnt;
        ++p;
    }
    int j = len + 2 * cnt - 1;
    p = str;
    for (int i = len-1; i >= 0; i--) {
        if (p[i] == ' ') {
            strncpy(p+j-2, "%20", 3);
            j-=3;
        }
        else {
            p[j] = p[i];
            j--;
        }
    }
}