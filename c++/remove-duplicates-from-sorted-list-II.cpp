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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode h(0);
        h.next = head;
        ListNode* pre = &h;
        while (head != NULL) {
            ListNode* next = head->next;
            if (next != NULL && next->val == head->val) {
                int val = head->val;
                while (head != NULL && head->val == val) {
                    pre->next = head->next;
                    delete head;
                    head = pre->next;
                }
            } else {
                pre = head;
                head = head->next;
            }
        }
        return h.next;
    }
};