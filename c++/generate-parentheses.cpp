#include <string>
#include <vector>
using namespace std;

/*
针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：
左括号的个数大于等于右括号的个数。所以，我们就可以按照
这个规则去打印括号：假设在位置k我们还剩余left个左括号和
right个右括号，如果left>0，则我们可以直接打印左括号，而
不违背规则。能否打印右括号，我们还必须验证left和right的
值是否满足规则，如果left>=right，则我们不能打印右括号，
因为打印会违背合法排列的规则，否则可以打印右括号。如果
left和right均为零，则说明我们已经完成一个合法排列，可以
将其打印出来。通过深搜，我们可以很快地解决问题.
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return allCase;
    }
private:
    vector<string> allCase;
    void generate(int leftNum, int rightNum, string s) {
        if (leftNum == 0 && rightNum == 0) {
            allCase.push_back(s);
        }
        if (leftNum > 0) {
            generate(leftNum-1, rightNum, s+"(");
        }
        if (rightNum > 0 && leftNum < rightNum) {
            generate(leftNum, rightNum-1, s+")");
        }
    }
};


/*
数组的入栈出栈顺序问题：给定一个长度为n的不重复数组，
求所有可能的入栈出栈顺序。该问题解的个数也是卡特兰数，
根据上面的思路，我们也可以写出一个类似的代码
*/
#include <stack>
#include <deque>
using namespace std;

class Solution2 {
public:
	vector<deque<int> > generateInOutStak(int n) {
		generate();
		return allCase;
	}
private:
	vector<deque<int> > allCase;
	deque<int> q, seq;
	stack<int> s;
	void generate(int in, int out) {
		if (!in && !out) {
			allCase.push_back(q);
		}
		if (in > 0) {
			s.push(seq.front());
			seq.pop_front();
			generate(in-1, out);
			seq.push_front(s.top());
			s.pop();
		}
		if (out > 0 && in < out) {
			q.push_back(s.top());
			s.pop();
			generate(in, out-1);
			s.push(q.back());
			q.pop_back();
		}
	}
};
/*
上述代码由于采用了栈和队列模仿整个过程，
所以显得略微复杂，但是代码的基本结构还
是符合一个类似的基本规则：在某一个特定
时刻，入栈的次数大于或者等于出栈的次数。
在生成括号的问题中，我们利用一个string
来保存结果，由于打印左括号时不影响打印
右括号，所以无需复杂的状态恢复。在入栈
出栈顺序问题中，由于两次递归调用共享同
一个栈和队列，所以我们需要手动恢复其内
容。在恢复时，队列会从头部删除和添加，
所以我们采用了deque，它可以在头部添加
和删除元素。queue只能在头部删除元素，
所以没有采用。
*/
