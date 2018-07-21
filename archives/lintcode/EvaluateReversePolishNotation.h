/**

求逆波兰表达式的值。

在逆波兰表达法中，其有效的运算符号包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰计数表达。

样例
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
说明
什么是逆波兰表达式？

http://en.wikipedia.org/wiki/Reverse_Polish_notation

*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> s;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& tk = tokens[i];
            if (!isdigit(tk[0]) && tk.length() == 1) {
                int val = s.top(); s.pop();
                switch (tk[0]) {
                    case '+': s.top() += val; break;
                    case '-': s.top() -= val; break;
                    case '*': s.top() *= val; break;
                    case '/': s.top() /= val; break;
                }
            }
            else {
                s.push(stoi(tk));
            }
        }
        return s.top();
    }
};

