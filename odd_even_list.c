/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity
and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    if ( head == NULL ) return NULL;

    struct ListNode * odd = head;
    struct ListNode * even = head->next;
    struct ListNode * evenHead = head->next;   // 奇链表的表头保存下来

    /* 因为原始链表奇偶元素交替排列的，所以可以分成奇偶两个链表，
     * 依次交替链接。最后再把两个链表链接上
     */
    while( even && even->next )
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    /* 将两个链表链接起来 */
    odd->next = evenHead;

    return head;

}
