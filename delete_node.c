/*
Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node.Supposed the linked list is 1 -> 2 -> 3 -> 4
and you are given the third node with value 3, the linked list should become
1 -> 2 -> 4 after calling your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
        *node = *(node->next);   // 把当前节点的内容改为下个节点的内容，相当于memcpy
}
