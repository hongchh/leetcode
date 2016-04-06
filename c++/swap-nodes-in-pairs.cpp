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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (pre != NULL && cur != NULL) {
            swap(pre->val, cur->val);
            pre = cur->next;
            if (pre != NULL)
            cur = pre->next;
        }
        return head;
    }
};