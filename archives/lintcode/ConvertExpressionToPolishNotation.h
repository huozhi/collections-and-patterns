/**

给定一个表达式字符串数组，返回该表达式的波兰表达式。（即去掉括号）


样例
对于 [(5 − 6) * 7] 的表达式（该表达式可表示为 ["(", "5", "−", "6", ")", "*", "7"]），其对应的波兰表达式为 [* - 5 6 7]（其返回的数值为["*", "−", "5", "6", "7"]）。

说明
波兰表达 的定义:

http://en.wikipedia.org/wiki/Polish_notation
http://baike.baidu.com/view/7857952.htm


*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */

    int rank(char op) {
        switch (op) {
            case '+':
            case '-':
                return 0;
            case '*':
            case '/':
                return 1;
            case '(':
            case ')':
                return 2;
        }
        return -1;
    }

    vector<string> convertToPN(vector<string> &expression) {
        // write your code here
        vector<string> result;
        stack<char> s;

        int n = expression.size();
        for (int i = n - 1; i >= 0; i--) {
            string &tk = expression[i];
            if (!isdigit(tk[0]) && tk.length() == 1) {
                char op = tk[0];
                if (op == '(') {
                    while (s.top() != ')') {
                        result.push_back(string(1, s.top()));
                        s.pop();
                    }
                    s.pop();
                }
                else if (s.empty() || s.top() == ')' || rank(op) >= rank(s.top())) {
                    s.push(op);
                }
                else {
                    result.push_back(string(1, s.top()));
                    s.pop();
                    i++;
                }
            }
            else {
                result.push_back(tk);
            }
        }
        while (!s.empty()) {
            result.push_back(string(1, s.top()));
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};