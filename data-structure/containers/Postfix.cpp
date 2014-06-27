/*
+-----------------------------------------------------------------------+
| C++ Code postfix calculator                                           |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <queue>
#include <string>
using namespace std;

#define WA  (1<<30)

int calc(int first, int second, char op);
int stoi(string s);

bool isoper(const char& c) {
    return (c=='+' || c=='-' || c=='/' || c=='*');
}

int stoi(string s) {
    int ans = 0;
    int mul = 1;
    unsigned int i = s.size();
    while (i-- && isdigit(s[i])) {
        ans += ((s[i] - '0') * mul);
        mul *= 10;
    }
    if(isdigit(s[i])) {
        ans += ((s[i] - '0') * mul);
    }
    else if(s[i]=='-') {
        ans = -ans;
    }
    return ans;
}

int calc(int first, int second, char op) {

    switch(op) {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    }
    return WA;
}

stack<int> res;
stringstream ss;

int main() {
    string exp, integer;
    getline(cin, exp);
    ss << exp;
    queue<string> postfix;

    while (ss>>integer) {
        postfix.push(integer);
    }

    while (!postfix.empty()) {
        string fro = postfix.front();
        // digit
        if (!isoper(fro[0])) {
            int temp = ::stoi(fro);
            res.push(temp);

        }
        // oper
        else if (isoper(fro[0])){
            if (!res.empty()) {
                int temp = res.top();
                res.pop();
                //fro is oper
                res.top() = calc(res.top(), temp, fro[0]);
            }
        }
        postfix.pop();
    }
    if (!res.empty()) {
        cout << res.top() << endl;
    }
    return 0;
}
