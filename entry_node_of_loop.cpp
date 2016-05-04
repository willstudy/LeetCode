/*
求有环链表的环开始的位置：

思路：
设一个快指针(走两步)，一个慢指针(走一步)，当相遇时，设慢指针走了离环开始的位置n步，
设环的长度为L，链表开始的位置距环的位置为K长度，那么慢指针共走了 K + n 步
因为快指针跟上了慢指针，实际上快指针多走了环的长度L，所以有

2*(k+n) = k + n + L  => L = k + n 所以此时慢指针距离环开始的位置就是 k 步

再走k步就可以到达环开始的位置了
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if( pHead == NULL || pHead->next == NULL ) return NULL;

        ListNode * fast = pHead;
        ListNode * slow = pHead;

        while( fast && fast->next ) {

            /* 不包含环 */
            slow = slow->next;
            /* 不包含环的情况 */
            fast = fast->next->next;

            if( fast == slow ) {
                slow = pHead;
                while( slow != fast ) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return false;
    }
};
