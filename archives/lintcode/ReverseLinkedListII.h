/**
翻转链表中第m个节点到第n个节点的部分

注意
m，n满足1 ≤ m ≤ n ≤ 链表长度

样例
给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null

挑战
在原地一次翻转完成

*/

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head, *next;
        for (int i = 1; i < m; i++) {
            prev = prev->next;
            curr = curr->next;
        }
        ListNode *start = curr, *mark = prev;
        for (int i = m; i <= n; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = next;
        mark->next = prev;
        return dummy.next;
    }
};

