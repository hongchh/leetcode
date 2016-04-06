#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
    	string expr = "";
        for (int i = 0; i < s.size(); ++i) {
        	if (s[i] != ' ' && s[i] != '\"')
        		expr += s[i];
        }
        for (int i = 0; i < expr.size(); ++i) {
        	if (expr[i] == '-' && (i == 0 || expr[i+1] == '(')) {
        		data.push(0);
        		op.push('-');
        	}
        	if (expr[i] == '+' && (i == 0 || expr[i+1] == '(')) {
        		data.push(0);
        		op.push('-');
        	}
        	if (expr[i] >= '0' && expr[i] <= '9') {
        		int num = 0;
        		while (expr[i] >= '0' && expr[i] <= '9' && i < expr.size()) {
        			num = num*10 + (expr[i]-'0');
        			++i;
        		}
        		data.push(num);
        	}
        	if (expr[i] == '+' || expr[i] == '-') {
        		while (!op.empty() && op.top() != '(') {
        			int a = data.top();
        			data.pop();
        			int b = data.top();
        			data.pop();
        			if (op.top() == '+')
        				data.push(b+a);
        			else
        				data.push(b-a);
        			op.pop();
        		}
        		op.push(expr[i]);
        	}
        	if (expr[i] == '(') op.push(expr[i]);
        	if (expr[i] == ')') {
        		while (op.top() != '(') {
        			int a = data.top();
        			data.pop();
        			int b = data.top();
        			data.pop();
        			if (op.top() == '+')
        				data.push(b+a);
        			else
        				data.push(b-a);
        			op.pop();
        		}
        		op.pop();
        	}
        }
        while (!op.empty()) {
        	int a = data.top();
        	data.pop();
        	int b = data.top();
        	data.pop();
        	if (op.top() == '+')
        		data.push(b+a);
        	else
        		data.push(b-a);
        	op.pop();
        }
        int ans = data.top();
        data.pop();
        return ans;
    }
private:
    stack<int> data;
    stack<char> op;
};
