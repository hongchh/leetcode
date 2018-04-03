/*
 * 思路: 计算两个链表长度，将开头多余的节点去掉，从相同长度的位置开始向后找公共节点
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
        	return NULL;
        int lenA = 0, lenB = 0;
        ListNode* temp = headA;
        while (temp != NULL) {
        	++lenA;
        	temp = temp->next;
        }
        temp = headB;
        while (temp != NULL) {
        	++lenB;
        	temp = temp->next;
        }
        if (lenA > lenB)
        	for (int i = 0; i < lenA-lenB; ++i)
        		headA = headA->next;
        else if (lenB > lenA)
        	for (int i = 0; i < lenB-lenA; ++i)
        		headB = headB->next;
        while (headA != headB) {
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }
};
