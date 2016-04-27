/*
min函数栈，可以时刻记录着栈中的最小元素
*/
class Solution {
public:
    stack<int> m_data;
    stack<int> m_min;

    void push(int value) {
        m_data.push(value);

        if( m_min.size() == 0 || m_min.top() > value )
            m_min.push( value );
        else
            m_min.push( m_min.top() );
    }
    void pop() {
        int value = m_data.top();
        m_data.pop();
        m_min.pop();
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
};
