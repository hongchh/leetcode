#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                calculate('+');
            } else if (tokens[i] == "-") {
                calculate('-');
            } else if (tokens[i] == "*") {
                calculate('*');
            } else if (tokens[i] == "/") {
                calculate('/');
            } else {
                data.push(str2int(tokens[i]));
            }
        }
        return data.top();
    }
private:
    stack<int> data;
    void calculate(char op) {
        int a = data.top();
        data.pop();
        int b = data.top();
        data.pop();
        if (op == '+') data.push(b+a);
        else if (op == '-') data.push(b-a);
        else if (op == '*') data.push(b*a);
        else data.push(b/a);
    }
    int str2int(string str) {
        int num = 0, i = 0;
        bool is_negative = false;
        if (str[0] == '-') is_negative = ++i;
        if (str[0] == '+') ++i;
        for (; i < str.size(); ++i) {
            num = num * 10 + (str[i]-'0');
        }
        return is_negative ? -num : num;
    }
};
