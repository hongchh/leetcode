#include <queue>
using namespace std;
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        sEntry.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (sEntry.size() == 1) {
            sEntry.pop();
        } else {
            while (sEntry.size() > 1) {
                temp.push(sEntry.front());
                sEntry.pop();
            }
            sEntry.pop();
            while (!temp.empty()) {
                sEntry.push(temp.front());
                temp.pop();
            }
        }
    }

    // Get the top element.
    int top() {
        if (sEntry.size() == 1) {
            return sEntry.front();
        } else {
            while (sEntry.size() > 1) {
                temp.push(sEntry.front());
                sEntry.pop();
            }
            int x = sEntry.front();
            temp.push(x);
            sEntry.pop();
            while (!temp.empty()) {
                sEntry.push(temp.front());
                temp.pop();
            }
            return x;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return sEntry.empty();
    }
private:
    queue<int> sEntry;
    queue<int> temp;
};
