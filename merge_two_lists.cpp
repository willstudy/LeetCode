/*
Merge two sorted linked lists and return it as a new list. The new list should be
made by splicing together the nodes of the first two lists.
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
/*
 *  先把要合并得到的单链表的头部得到，然后根据两个链表值的比较，以尾插法先后插入
 *  这里要注意的是，要对链表的next指针进行遍历（也就是对next指针的赋值过程，val字段则可忽略）
 */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * head, *l;
        ListNode * p = l1;
        ListNode * q = l2;

        if( p && q )
        {
            if( p->val < q->val )
            {
                head = p;
                l = head;
                p = p->next;
            }
            else
            {
                head = q;
                l = head;
                q = q->next;
            }
        }
        else if( p )
        {
            head = p;
            l = head;
            p = p->next;

            while( p )
            {
                l->next = p;
                l = l->next;
                p = p->next;
            }

            l = NULL;
            return head;
        }
        else if( q )
        {
            head = q;
            l = head;
            q = q->next;

            while( q )
            {
                l->next = q;
                l = l->next;
                q = q->next;
            }
            l = NULL;
            return head;
        }

        else return NULL;

        while( p && q )
        {
            if( p->val < q->val )
            {
                l->next = p;
                l = l->next;
                p = p->next;
            }
            else
            {
                l->next = q;
                l = l->next;
                q = q->next;
            }
        }

        while( p )
        {
            l->next = p;
            l = l->next;
            p = p->next;
        }

        while( q )
        {
            l->next = q;
            l = l->next;
            q = q->next;
        }

        l = NULL;

        return head;
    }
};
