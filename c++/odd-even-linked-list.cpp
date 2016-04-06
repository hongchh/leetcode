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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0), even(0);
        ListNode* lastOddNode = &odd;
        ListNode* lastEvenNode = &even;
        int len = 1;
        while (head != NULL) {
            if (len%2 == 1) {
                lastOddNode->next = head;
                lastOddNode = head;
            } else {
                lastEvenNode->next = head;
                lastEvenNode = head;
            }
            head = head->next;
            ++len;
        }
        lastOddNode->next = even.next;
        lastEvenNode->next = NULL;
        return odd.next;
    }
};