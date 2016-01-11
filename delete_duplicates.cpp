/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL ) return head;

        ListNode *p = head;
        ListNode *q = p->next;

        while( p != NULL )
        {
            q = p->next;
            while( q != NULL && q->val == p->val   )
            {
                ListNode * tmp = q;
                q = q->next;
                free(tmp);
            }
            p->next = q;    // 将值相等的节点去掉
            p = q;
        }
        return head;
    }
};
