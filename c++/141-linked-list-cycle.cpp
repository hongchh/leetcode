// 用O(1)的空间判断链表是否有环
// 思路：两个指针，一个快一个慢，如果有环一定会相遇
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != NULL && fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            if (slow != NULL && slow == fast)
                return true;
        }
        return false;
    }
};
