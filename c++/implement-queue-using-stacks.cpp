#include <stack>
using namespace std;
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        qEntry.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!qEntry.empty()) {
            temp.push(qEntry.top());
            qEntry.pop();
        }
        temp.pop();
        while (!temp.empty()) {
            qEntry.push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while (!qEntry.empty()) {
            temp.push(qEntry.top());
            qEntry.pop();
        }
        int x = temp.top();
        while (!temp.empty()) {
            qEntry.push(temp.top());
            temp.pop();
        }
        return x;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return qEntry.empty();
    }
private:
    stack<int> qEntry;
    stack<int> temp;
};
