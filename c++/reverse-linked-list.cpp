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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pre = head;
        ListNode* mid = pre->next;
        ListNode* fin = mid->next;
        while (fin != NULL) {
            mid->next = pre;
            pre = mid;
            mid = fin;
            fin = fin->next;
        }
        mid->next = pre;
        head->next = NULL;
        return mid;
    }
};
