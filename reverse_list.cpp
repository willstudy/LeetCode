/*
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode * node = head;
        ListNode * result = NULL;
        ListNode * p = NULL;

        while( node != NULL )
        {
            p = node->next;    // save the next node's address
            node->next = result;
            result = node;
            node = p;
        }

        return result;
    }
};
