//still has some bugs....
// correct test case: 1 + 2 * 3

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

/**
 * infix:
 * a + b * c
 * crrosponding postfix:
 * a b c * +
 **/


int level(const char& op) {
    switch(op) {
    case '(':
    case ')':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
    default:
        return 1;
    }
}

bool isoper(const char& c) {
    switch(c) {
    case '+':
    case '-':
    case '*':
    case '/':
    //case '(':
        return true;
    default:
        return false;
    }
}

// parenthese

bool islp(const char& c) {
    return (c == '(');
}

bool isrp(const char& c) {
    return (c == ')');
}


//string infix;
queue<string> postfix;
stringstream ss;
stack<char> oper;
char buf[100001], infix[100002];

int main() {

    while (cin.getline(infix, 100000)) {
//        cout << infix << endl;
        ss << infix;
        //cin.getline(buf, 2);
    //    unsigned int i;
        string digit, temp;
        while (ss >> temp) {

            if (isdigit(temp[0])) {
                postfix.push(temp); // push digit
            }
            // is operator
            else {
                if (!isrp(temp[0])) {
                    if (oper.empty()) {
                        //cout << "opempty: " << temp[0] << endl;
                        oper.push(temp[0]);
                    }
                    else if (!oper.empty() && level(oper.top()) >= level(temp[0])) {
                        do {
                            //cout << "op>=: " << oper.top() << endl;
                            postfix.push(string(oper.top() + ""));
                            cout << "op>=: " << postfix.back() << endl;
                            oper.pop();
                        } while (!oper.empty() && level(oper.top())<level(temp[0]));

                    }
                    else if (!oper.empty() && level(oper.top()) < level(temp[0])) {
                        oper.push(temp[0]);
                        cout << "op<: " << temp[0] << endl;
                    }
                }
                else {
                    while (!oper.empty() && oper.top()!='(') {
                        postfix.push(string(oper.top() + ""));
                        oper.pop();
                    }
                    oper.pop(); // remove left parenthese
                }
            }
        }

        // output
        while (!postfix.empty()) {
            cout << postfix.front() << ' ';
            postfix.pop();
        }

            // pop stack
        while (!oper.empty()) {
            cout << oper.top() << ' ';
            oper.pop();
        }
        cout << endl;
//        infix.clear();
    }
    return 0;
}
