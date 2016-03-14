/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode * tmp = NULL;

        while( head != NULL && head->val == val )
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }

        if( head == NULL ) return NULL;

        ListNode * pre = head;
        ListNode * cur = head->next;

        while( cur != NULL )
        {
            if( cur->val == val )
            {
                pre->next = cur->next;
                tmp = cur;
                cur = cur->next;
                free( tmp );
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
