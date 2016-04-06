// 在O(1)的时间内找出栈中的最小值
// 思路：开另外一个栈记录最小值，保持最小值在此栈栈顶
class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || minStk.top() >= x)
            minStk.push(x);
    }

    void pop() {
        int x = stk.top();
        stk.pop();
        if (x == minStk.top())
            minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
private:
    stack<int> stk;
    stack<int> minStk;
};
