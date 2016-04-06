// 用O(1)的空间判断链表是否有环，且找出环的其实节点
// 思路：一快一慢指针，第一次相遇时表示有环，
// 此时把慢指针移到链表头部并将两指针的速度都设为1，
// 等到它们第二次相遇的节点即为环开始节点
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            if (slow == NULL || fast == NULL)
                return NULL;
        } while (slow != fast);
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
