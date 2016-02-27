/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *p_A = headA;
        ListNode *p_B = headB;

        int cnt_A = 0;
        int cnt_B = 0;

        if( headA == NULL || headB == NULL )
        {
            return NULL;
        }
        /* 先计算每个链表的长度 */
        while( p_A != NULL )
        {
            cnt_A++;
            p_A = p_A->next;
        }
        while( p_B != NULL )
        {
            cnt_B++;
            p_B = p_B->next;
        }

        p_A = headA;
        p_B = headB;

        /* 计算偏移，从哪里开始比较，题目中的意思是第一个匹配了，后面的也就匹配了
         * 就可以直接返回了
         */
        if( cnt_A > cnt_B )
        {
            int offset = cnt_A - cnt_B;

            for( int i = 0; i < offset; i++ )
            {
                p_A = p_A->next;
            }

        }
        else if( cnt_A < cnt_B )
        {
            int offset = cnt_B - cnt_A;

            for( int i = 0; i < offset; i++ )
            {
                p_B = p_B->next;
            }
        }
        while( p_A != NULL && p_B != NULL )
        {
            if( p_A->val == p_B->val )
            {
                return p_A;
            }

            p_A = p_A->next;
            p_B = p_B->next;
        }

        return NULL;
    }
};
