#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (char ch : infix) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        else {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;

    return 0;
}