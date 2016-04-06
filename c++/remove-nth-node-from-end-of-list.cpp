/*
 * 双指针，两个指针相差n-1步，同时移动两个指针，当快指针到达链表结尾时，
   慢指针所指即为要删除的点,刚好遍历一次链表完成
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; ++i) {
        	fast = fast->next;
        }
        ListNode* temp;
        while (fast != NULL) {
        	fast = fast->next;
        	temp = slow;
        	slow = slow->next;
        }
        if (slow == head) {
        	head = head->next;
        	delete slow;
        } else {
        	temp->next = slow->next;
        	delete slow;
        }
        return head;
    }
};