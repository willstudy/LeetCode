/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

这一题比较重要的是找到头结点：

思路：先找到头结点，设置pre指针，往后遍历的时候遇到重复的节点时，要删除
直到遇到pre->val != pre->next->val时更新prev指针。注意指针为空的情况
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
    ListNode * getHead(ListNode * pHead)
    {
        int count = 0;
        while (pHead != NULL && pHead->next != NULL
                && pHead->val == pHead->next->val)
        {
            count++;
            ListNode * tmp = pHead;
            pHead = pHead->next;
            free(tmp);
            tmp = NULL;
        }
        if (count == 0)
            return pHead;
        else
            return getHead(pHead->next);
    }

    ListNode* deleteDuplication(ListNode* pHead)
    {
		if( pHead == NULL ) return NULL;

        pHead = getHead(pHead);
        ListNode * ptr = pHead;

        if( pHead == NULL ) return NULL;

        ListNode * pre = ptr;
        while( ptr->next ) {
            if( ptr->val != ptr->next->val ) {
                pre = ptr;
                ptr = ptr->next;
            }
            else {
                while( ptr->next && ptr->val == ptr->next->val ) {
                    ListNode * tmp = ptr;
                    ptr = ptr->next;
                    free(tmp);
                    tmp = NULL;
                }
                ListNode * tmp = ptr;
                ptr = ptr->next;
                free(tmp);
                tmp = NULL;
                pre->next = ptr;

                if( ptr == NULL ) return pHead;
            }
        }

        return pHead;
    }
};
