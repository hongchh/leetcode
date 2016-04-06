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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* sortedList = head;
        head = head->next;
        sortedList->next = NULL;
        while (head != NULL) {
            ListNode* pos = sortedList;
            ListNode* pre = NULL;
            while (pos != NULL && pos->val < head->val) {
                pre = pos;
                pos = pos->next;
            }
            ListNode* temp = head;
            head = head->next;
            if (pos == sortedList) {
                temp->next = pos;
                sortedList = temp;
            } else {
                temp->next = pos;
                pre->next = temp;
            }
        }
        return sortedList;
    }
};