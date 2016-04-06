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
        if (head == NULL) return head;
        ListNode h(0);
        h.next = head;
        ListNode* cur = head;
        ListNode* pre = &h;
        while (cur != NULL) {
            if (cur->val == val) {
                cur = cur->next;
                delete pre->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return h.next;
    }
};