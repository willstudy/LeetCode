/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/
/*
 * 用队列实现栈功能，这里把队列的头部当做栈顶
 */
 /*
 * 栈顶放在队列的头部
 */
class Stack {
private:
    queue<int> Q;       
    queue<int> temp;
public:
    // Push element x onto stack.
    void push(int x) {
        temp.push(x);
        while (!Q.empty()) {
            temp.push(Q.front());
            Q.pop();
        }
        Q.swap(temp);
    }

    // Removes the element on top of the stack.
    void pop() {
        Q.pop();
    }

    // Get the top element.
    int top() {
        return Q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
};
