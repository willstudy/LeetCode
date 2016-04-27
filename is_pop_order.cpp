/*
判断一个数列是否是另一个以另一个数列顺序进栈的出栈顺序？

例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1
是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> S;
        int push_size = pushV.size();
        int pop_size = popV.size();

        if( push_size == 0 || pop_size == 0 ) return false;

        int index = 0;
        for( int i = 0; i < push_size; i++ ) {
            if( pushV[i] == popV[index] ) {
                if( S.empty() && index == pop_size - 1 ) return true;

                index++;
            }
            else {
                S.push(pushV[i]);
            }
        }

        while( !S.empty() && index < pop_size ) {
            int value = S.top();
            if( value != popV[index] ) return false;
            S.pop();
            index++;
        }

        return true;
    }
};
