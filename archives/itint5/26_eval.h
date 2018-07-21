/*

给定一个表达式字符串，其中只包含非负整数，加法，减法以及乘法符号，例如7+3*4*5+2+4-3-1。请写程序计算该表达式的值。

*/

int next_int(const string& expr, int &i) {
    int num = 0;
    while (isdigit(expr[i])) {
        num = num * 10 + (expr[i] - '0');
        ++i;
    }
    return num;
}


int evaluate(const string& expr) {
    int res = 0, val = 1;
    for (int i = 0; i < expr.size(); i++) {
        int next = next_int(expr, i);
        val *= next;
        if (i == expr.size()) {
            res += val;
        }
        if (expr[i] == '*')
            continue;
        else if (expr[i] == '+') {
            res += val;
            val = 1;
        }
        else if (expr[i] == '-') {
            res += val;
            val = -1;
        }
    }
    return res;
}