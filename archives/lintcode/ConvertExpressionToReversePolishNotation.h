/**

给定一个表达式字符串数组，返回该表达式的逆波兰表达式（即去掉括号）。

样例
对于 [3 - 4 + 5]的表达式（该表达式可表示为["3", "-", "4", "+", "5"]），返回 [3 4 - 5 +]（该表达式可表示为 ["3", "4", "-", "5", "+"]）。

其他测试样例：

["2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"] => ["2","6","*","23","7","+","1","2","+","/","-"]

*/

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */

    int rank(const char op) {
        switch (op) {
            case '+':
            case '-':
                return 0; break;
            case '*':
            case '/':
                return 1; break;
            case '(':
            case ')':
                return 2; break;
        }
        return -1;
    }

    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string> post;
        int n = expression.size();
        stack<char> s;
        for (int i = 0; i < n; i++) {
            string& tk = expression[i];
            if (!isdigit(tk[0]) && tk.length() == 1) {
                char op = tk[0];
                if (s.empty() || op == '(')
                    s.push(op);
                else {
                    if (op == ')') {
                        while (s.top() != '(') {
                            post.push_back(string(1, s.top()));
                            s.pop();
                        }
                        s.pop();
                    }
                    else if (rank(op) <= rank(s.top())) {
                        while (!s.empty() && rank(op) <= rank(s.top()) && s.top() != '(') {
                            post.push_back(string(1, s.top()));
                            s.pop();
                        }
                        s.push(op);
                    }
                    else
                        s.push(op);
                }
            }
            else {
                post.push_back(tk);
            }
        }
        while (!s.empty()) {
            post.push_back(string(1, s.top()));
            s.pop();
        }
        return post;
    }
};