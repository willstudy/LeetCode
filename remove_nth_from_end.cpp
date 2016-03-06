/*
Given a linked list, remove the nth node from the end of list and return its head.
For example,
   Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * pre = new ListNode(0);
        ListNode * cur = head;
        pre->next = head;

        /* 使用两个指针进行移动，其中这两个指针的距离是n */

        for( int i = 0; i < n; i++ )
        {
            cur = cur->next;
        }

        ListNode * before = pre;
        while( cur )
        {
             /*  使用2个指针进行标记 */
            cur = cur->next;
            before = before->next;
        }
        ListNode * tmp = before->next;
        before->next = before->next->next;
        delete( tmp );

        ListNode * result = pre->next;
        delete( pre );

        return result;
 /*
        vector<ListNode *> array;
        ListNode * node = head;

        while( node != NULL )
        {
           array.push_back(node);
           node = node->next;
        }

        int size = array.size();
        int index = size -n - 1;

        if( index < 0 )
        {
            delete( array[0] );
            return array[1];    // 下标小于0时，直接返回第二个结点
        }
        else
        {
            array[size - n - 1]->next = array[size -n]->next;
            delete(array[size -n]);
        }

        return head;
*/
    }
};
