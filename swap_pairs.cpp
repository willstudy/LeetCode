/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {

        if( head == NULL ) return NULL;

        ListNode * new_head = head;
        ListNode * prev = head;
        ListNode * cur = prev->next;

        if( cur == NULL ) return new_head;
        else {
            new_head = cur;
            prev->next = cur->next;
            cur->next = prev;
        }

        ListNode * p = prev->next;
        ListNode * q;

        while( p )
        {
            if( p->next == NULL ) break;

            q = p->next;
            p->next = q->next;
            q->next = p;
            prev->next = q;

            prev = p;
            p = prev->next;
        }

        return new_head;
    }
};
