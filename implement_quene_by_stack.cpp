/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top,
peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a
stack by using a list or deque (double-ended queue), as long as you use only standard
operations of a stack.You may assume that all operations are valid (for example,
no pop or peek operations will be called on an empty queue).
*/
/*
 * 个人感觉这一题很无聊，函数定义的也不规范，没有给出数据成员！！！自己瞎定义了两个栈成员s1,s2
 */
class Queue {
public:
    stack<int> s1, s2;
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if( s1.empty() ) return ;

        while( !s1.empty() )
        {
            s2.push(s1.top());
            s1.pop();
        }

        s2.pop();

        while( !s2.empty() )
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if( s1.empty() ) return NULL;
        while( !s1.empty() )
        {
            s2.push(s1.top());
            s1.pop();
        }

        int result = s2.top();

        while( !s2.empty() )
        {
            s1.push(s2.top());
            s2.pop();
        }

        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
