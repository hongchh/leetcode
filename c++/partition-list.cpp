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
    ListNode* partition(ListNode* head, int x) {
        ListNode less(0), notLess(0);
        ListNode* lastLess = &less;
        ListNode* lastNotLess = &notLess;
        while (head != NULL) {
            if (head->val < x) {
                lastLess->next = head;
                lastLess = head;
            } else {
                lastNotLess->next = head;
                lastNotLess = head;
            }
            head = head->next;
        }
        lastLess->next = notLess.next;
        lastNotLess->next = NULL;
        return less.next;
    }
};