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
        if (head == NULL) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != NULL) {
            if (cur->val == pre->val) {
                ListNode* temp = cur;
                cur = cur->next;
                pre->next = cur;
                delete temp;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};